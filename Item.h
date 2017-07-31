#ifndef _ITEM_
#define _ITEM_
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class Item { 

protected:

	int id;
	double price;
	string name;
	string description;

public:

	Item() {}
	Item(double _price, string _name, string _descr);
	virtual ~Item(); //virtual destructor

	virtual void printItem() const;
	int getId() const { return id; }
	string getName() const { return name; }
	void setName(string _name) { name = _name; }
	double getPrice() const { return price; }
	void setPrice(double _price) { if(price > 0) price = _price; }
	string getDescription() const { return description; }
	void setDescription(string des) { description = des; }
};

#endif //_ITEM_