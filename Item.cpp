#include "Item.h"

Item::Item(double _price, string _name, string _descr) : price(_price), name(_name), description(_descr) {

	static int idStart = 16534; //some random number to make it realistic
	id = (idStart += 3347); // likewise
}


void Item::printItem() const {

	cout << setw(10) << left << id
		 << setw(8) << left << price
		 << setw(15) << left << name
		 << setw(30) << left << description;
}

Item::~Item() {}