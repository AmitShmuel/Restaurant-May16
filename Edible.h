#ifndef _EDIBLE_
#define _EDIBLE_
#include "Item.h"

enum EdType { Breakfast, Italian, Meat, Dessert };

class Edible : public virtual Item {

protected:

	EdType edType;
	//protected Constructor, will be called only when Special object is created
	Edible(EdType _edType) : edType(_edType) {}

public:

	Edible(double _price, string _name, string _descr, EdType _type) : Item(_price, _name, _descr), edType(_type) {}

	string getType(EdType) const;
	void setType(EdType type) { edType = type; }
	//Overrides
	virtual void printItem() const { Item::printItem(); cout << setw(10) << left << getType(edType); }
};

#endif //_EDIBLE_
