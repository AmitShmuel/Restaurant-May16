#ifndef _SPBeverage_
#define _SPBeverage_

#include "Special.h"
#include "SharedPtr.h"

class SPBeverage {

	SharedPtr<Beverage> value;

public:

	SPBeverage(double _price, string _name, string _descr, BevType _type) 
		: value(new Beverage(_price, _name, _descr, _type)) {}

	string getType(BevType type) const { return value->getType(type); }
	void setType(BevType type) { value->setType(type); }
	void printItem() const { value->printItem(); }
};


#endif //_SPBeverage_
