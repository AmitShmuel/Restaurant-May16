#ifndef _BILL_
#define _BILL_
#include <vector>
#include "SharedPtr.h"
#include "SPBeverage.h"
#include "SPEdible.h"
#include "SPSpecial.h"
#include "Special.h"

class Bill {

	double total;
	int orderNum;
	static int orderCount; //incremented on each bill creation
	vector<SharedPtr<Item>> itemList;

public:
	Bill() : total(0), orderNum(++orderCount) {}
	~Bill();

	void printItemList() const;
	double getTotal() const { return total; }
	const vector<SharedPtr<Item>>& getItemList() const { return itemList; }
	void addItem(Item* item);
};
#endif //_BILL_