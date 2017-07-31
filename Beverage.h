#ifndef _BEVERAGE_
#define _BEVERAGE_
#include "Item.h"

enum BevType { SoftDrink, HotDrink, Wine, Liqour };

class Beverage : public virtual Item {

protected:

	BevType bevType;
	//protected Constructor, will be called only when Special object is created
	Beverage(BevType _bevType) : bevType(_bevType) {}

public:

	Beverage(double _price, string _name, string _descr, BevType _type) : Item(_price, _name, _descr), bevType(_type) {}

	string getType(BevType) const;
	void setType(BevType type) { bevType = type; }
	//Overrides
	virtual void printItem() const { Item::printItem(); cout << setw(10) << left << getType(bevType); }
};

#endif // _BEVERAGE_