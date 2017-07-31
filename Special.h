#ifndef _SPECIAL
#define _SPECIAL
#include "Edible.h"
#include "Beverage.h"

              //shared base inheritance
class Special : public Edible, public Beverage { 

public:

	Special(double _price, string _name, string _descr, EdType _etype, BevType _btype)
	: Item(_price, _name, _descr), Edible(_etype), Beverage(_btype) {}
	~Special() { ; }

	//Overrides
	virtual void printItem() const { Item::printItem(); cout << Edible::getType(edType) << " & " << Beverage::getType(bevType); }
};

#endif //_SPECIAL
