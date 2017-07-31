#ifndef _SHAREDPTR_
#define _SHAREDPTR_
#include "SPObject.h"

template<class T>
class SharedPtr {

	struct CountHolder : public SPObject
	{
//		~CountHolder() { delete pointee; } throws exception at end of program.. couldn't figure out what's going wrong..
		T* pointee;
	};

	CountHolder* counter;
	
	void init();
	void makeCopy();

public:

	SharedPtr(T* realPtr = 0);
	SharedPtr(const SharedPtr& rhs);
	~SharedPtr();
	SharedPtr& operator=(const SharedPtr& rhs);
	
	const T* operator->() const;
	T* operator->();
	const T& operator*() const;
	T& operator*();

	operator T*() { return counter->pointee; }
};

template<class T>
void SharedPtr<T>::init()
{
	if (counter->isShareable() == false)
	{
		T *oldValue = counter->pointee;
		counter = new CountHolder;
		counter->pointee = new T(*oldValue);
	}
	counter->addReference();
}

template<class T>
SharedPtr<T>::SharedPtr(T* realPtr)
	: counter(new CountHolder)
{

	counter->pointee = realPtr;
	init();
}

template<class T>
SharedPtr<T>::SharedPtr(const SharedPtr& rhs)
	: counter(rhs.counter)
{
	init();
}

template<class T>
SharedPtr<T>::~SharedPtr()
{
	counter->removeReference();
}

template<class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& rhs)
{
	if (counter != rhs.counter)
	{
		counter->removeReference();
		counter = rhs.counter;
		init();
	}
	return *this;
}

template<class T> 
void SharedPtr<T>::makeCopy() 
{ 
	if (counter->isShared())
	{
		T *oldValue = counter->pointee;
		counter->removeReference();
		counter = new CountHolder;
		counter->pointee = new T(*oldValue);
		counter->addReference();
	}
}

template<class T> 
const T* SharedPtr<T>::operator->() const 
{
	return counter->pointee;
}

template<class T> 
T* SharedPtr<T>::operator->() 
{ 
	makeCopy(); return counter->pointee;
}

template<class T> 
const T& SharedPtr<T>::operator*() const 
{
	return *(counter->pointee);
}

template<class T> 
T& SharedPtr<T>::operator*() 
{ 
	makeCopy(); return *(counter->pointee);
}

#endif //_SHAREDPTR_
