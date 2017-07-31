#include "Bill.h"

int Bill::orderCount = 0; //static member initialization


Bill::~Bill() {

	for (vector<SharedPtr<Item>>::iterator it = itemList.begin(); it != itemList.end(); ++it)
		if (*it != NULL)
			delete *it;
}


void Bill::printItemList() const {

	for (vector<SharedPtr<Item>>::const_iterator it = itemList.begin(); it != itemList.end(); ++it)
			cout << (*it)->getName() << ", ";
}


void Bill::addItem(Item* item) { 
	
	Special* sPtr = dynamic_cast<Special*>(item);
	if (sPtr != NULL)
	{
		itemList.push_back((new Special(*sPtr))); total += sPtr->getPrice();
	}
	else
	{
		Edible* ePtr = dynamic_cast<Edible*>(item);
		if (ePtr != NULL)
		{
			itemList.push_back((new Edible(*ePtr))); total += ePtr->getPrice();
		}
		else
		{
			Beverage* bPtr = dynamic_cast<Beverage*>(item);
			if (ePtr != NULL)
			{
				itemList.push_back((new Beverage(*bPtr))); total += bPtr->getPrice();
			}
		}
	}
}