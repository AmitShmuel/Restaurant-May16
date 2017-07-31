#ifndef _TABLE_
#define _TABLE_
#include "Bill.h"

class Table {

	Bill bill;
	string waiter;
	int diners;
	int tableID;
	static int idCount; //incremented on each table creation
	
public:

	Table() {}
	Table(int _diners , string _waiter) : diners(_diners), waiter(_waiter), tableID(++idCount) {}
		
	void cashOut();
	void printTable() const;
	int getTableID() const { return tableID; }
	void printBill() const { bill.printItemList(); }
	void addToBill(Item* item) { bill.addItem(item); }
	string getWaiter() const { return waiter; }
};
#endif //_TABLE_