#include "SPObject.h"

SPObject::SPObject()
	: refCount(0), shareable(true) {}

SPObject::SPObject(const SPObject&)
	: refCount(0), shareable(true) {}

SPObject& SPObject::operator=(const SPObject&)
{
	return *this;
}

SPObject::~SPObject() {} 

void SPObject::addReference()
{
	++refCount;
}

void SPObject::removeReference()
{
	if (--refCount == 0) delete this;
}

void SPObject::markUnshareable()
{
	shareable = false;
}

bool SPObject::isShareable() const
{
	return shareable;
}

bool SPObject::isShared() const
{
	return refCount > 1;
}