#ifndef _SPSpecial_
#define _SPSpecial_

#include "Special.h"
#include "SharedPtr.h"

class SPSpecial {

	SharedPtr<Special> value;

public:

	SPSpecial() {}
	SPSpecial(double _price, string _name, string _descr, EdType _etype, BevType _btype)
		: value(new Special(_price , _name , _descr , _etype , _btype)) {}

	void printItem() const { value->printItem(); }
};

#endif //_SPSpecial_