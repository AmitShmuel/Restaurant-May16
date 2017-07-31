#ifndef _SPEdible
#define _SPEdible

#include "Special.h"
#include "SharedPtr.h"

class SPEdible {

	SharedPtr<Edible> value;

public:

	SPEdible(double _price, string _name, string _descr, EdType _type)
		: value(new Edible(_price, _name, _descr, _type)) {}

	string getType(EdType type) const { return value->getType(type); }
	void setType(EdType type) { value->setType(type); }
	void printItem() const { value->printItem(); }
};


#endif //_SPEdible
