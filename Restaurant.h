#ifndef _RESTAURANT_
#define _RESTAURANT_
#include <cstdlib>
#include "Table.h"
#include <list>

class Restaurant {

	list<Table*> tables;
	vector<SharedPtr<Item>> menu;
	vector<SharedPtr<Item>> sales;
	const string waiters[4] = { "John" , "Mia" , "Mark" , "Jenny" }; 
	//private method to initialize the menu
	void initMenu(); 

public:

	Restaurant();
	~Restaurant();

	bool isEmpty() const { return tables.empty(); }
	int tablesNumber() const { return tables.size(); }
	void printMenu() const;
	void printTables() const;
	void printSales() const;
	void addTable(int _diners);
	void removeTable(Table* table) { tables.remove(table); }
	void order(Table* table);
	void editItem();
	//void editSpecial(SharedPtr<Special>);		crashes for some reason..
	//void editEdible(SharedPtr<Edible>);		couldn't figure it out..
	//void editBeverage(SharedPtr<Beverage>);	editItem() is used instead and works fine
	Item* findItem(int itemId);
	Table* findTable(int tableId);
	Table* getLastTable() const { return tables.back(); }
	
};
//ui module's functions, must use it in some methods.
string getChoice(); 
string yesOrNo();

#endif //_RESTAURANT_
