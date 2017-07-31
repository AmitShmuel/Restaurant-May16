#include "Restaurant.h"


void Restaurant::initMenu() {

	menu.push_back(new Edible(70, "Fried Egg", "2 eggs bla bla", Breakfast));
	menu.push_back(new Edible(70, "Pasta", "fotochini bla bla", Italian));
	menu.push_back(new Edible(120, "Steak", "well done bla bla", Meat));
	menu.push_back(new Edible(45, "Sufle", "Sweet chocolate bla", Dessert));
	menu.push_back(new Beverage(7, "Water", "Mineral bla bla", SoftDrink));
	menu.push_back(new Beverage(14, "Coffee", "hot coffee bla bla", HotDrink));
	menu.push_back(new Beverage(43, "Shardone", "well wine bla bla", Wine));
	menu.push_back(new Beverage(50, "Vodka", "Russian bla bla", Liqour));
	menu.push_back(new Special(80, "Kids Meal", "Shnitzel chips bla bla", Meat, SoftDrink));
	menu.push_back(new Special(90, "Late Night", "Hamburger bla bla", Meat, Liqour));
}


Restaurant::Restaurant() {

	try { 
		initMenu(); 
	} 
	catch (bad_alloc) { cerr << "Restaurant::initMenu() Items' allocation failed\n"; } 
}


Restaurant::~Restaurant() {
	
	for (list<Table*>::iterator it = tables.begin(); it != tables.end(); ++it)
		if(*it != NULL)
			delete *it;

	for (vector<SharedPtr<Item>>::iterator it = menu.begin(); it != menu.end(); ++it)
		if (*it != NULL)
			delete *it;
}


void Restaurant::printMenu() const {

	cout << setw(10) << left << "\nID"
		 << setw(9) << left << "PRICE"
		 << setw(15) << left << "NAME"
		 << setw(30) << left << "DESCRIPTION"
		 << setw(10) << left << "TYPE\n---------------------------------------------------------------------------\n";

	for (vector<SharedPtr<Item>>::const_iterator it = menu.begin(); it != menu.end(); ++it)
	{
		(*it)->printItem();
		cout << endl;
	}
	cout << endl;
}


void Restaurant::printSales() const {

	if (sales.empty())
	{
		cout << "There has been no sales for today yet..\n";
	}
	else
	{
		cout << "Today's sales are:\n"
		     << setw(10) << left << "\nID"
			 << setw(9) << left << "PRICE"
			 << setw(15) << left << "NAME"
			 << setw(30) << left << "DESCRIPTION"
			 << setw(10) << left << "TYPE\n---------------------------------------------------------------------------\n";
		double total = 0;
		for (vector<SharedPtr<Item>>::const_iterator it = sales.begin(); it != sales.end(); ++it)
		{
			(*it)->printItem();
			total += (*it)->getPrice();
			cout << endl;
		}
		cout << endl << "Total: " << total << endl;
	}
		
}

void Restaurant::printTables() const {

	cout << setw(6) << left << "\nID"
		 << setw(9) << left << "Diners"
		 << setw(7) << left << "Bill"
		 << "Order\n---------------------------------------------------------------------------\n";

	for (list<Table*>::const_iterator it = tables.begin(); it != tables.end(); ++it)
	{
		(*it)->printTable();
		cout << endl;
	}
}

void Restaurant::addTable(int _diners) {

	static int i = 0;
	tables.push_back(new Table(_diners , waiters[i]));
	cout << "\nThe table has been added, the waiter is " << waiters[i] << endl;
	i = (i+1) % 4; //incrementing i to choose different waiter, % 4 making i = 0 again.. (only 4 waiters)
}


Table* Restaurant::findTable(int tableId) {

	for (list<Table*>::iterator it = tables.begin(); it != tables.end(); ++it)
		if ((*it)->getTableID() == tableId)
			return *it;
	return NULL;
}


Item* Restaurant::findItem(int itemId) {

	for (vector<SharedPtr<Item>>::iterator it = menu.begin(); it != menu.end(); ++it)
		if ((*it)->getId() == itemId)
			return *it;
	return NULL;
}

void Restaurant::order(Table* table) {

	printMenu(); //letting the user choose items
	cout << "please choose items by their id, press '0' to finish\n";
	do
	{
		string input = getChoice();
		if (input == "0")
			return;
		else
		{
			Item* item;
			if ((item = findItem(atoi(input.c_str()))) != NULL) //searching item
			{
				table->addToBill(item); //found, adding to bill
				sales.push_back(item); // adding to sales
				cout << item->getName() << " was successfuly added\n";
			}
			else
				cerr << "there's not such item ";
		}
	} while (1);
}


void Restaurant::editItem() {

	string input;
	cout << "This option requires a manager password (123), \nplease provide it or press 0 to return to the main menu.. ";
	while (1)
	{
		input = getChoice();
		if (input == "0")
			return;
		else if (input != "123")
			cout << "password is incorrect! ";
		else {
			break;
		}
	}

	printMenu(); //letting the user choose items
	cout << "please choose the item you wish to change by it's id, press '0' to finish\n";
	do
	{
		input = getChoice();
		if (input == "0")
			return;
		else
		{
			Item* item;
			if ((item = findItem(atoi(input.c_str()))) != NULL) //searching item
			{
				system("cls||clear");
				item->printItem();
				cout << "\n\nwould you like to change the item's price? [1]Yes [2]No ";
				if ((input = yesOrNo()) == "1")
				{
					cout << "\nenter new price: ";
					while (1)
					{
						input = getChoice();
						double price = atoi(input.c_str());
						if (price > 0)
						{
							item->setPrice(price);
							break;
						}
						cout << "\nprice can only be positive number..";
					}
				}
				cout << "\nwould you like to change the item's name? [1]Yes [2]No ";
				if ((input = yesOrNo()) == "1")
				{
					cout << "\nenter new name: ";
					cin.ignore(10000, '\n');
					getline(cin, input);
					item->setName(input);
				}
				cout << "\nwould you like to change the item's description? [1]Yes [2]No ";
				if ((input = yesOrNo()) == "1")
				{
					cout << "\nenter new description: ";
					cin.ignore(10000, '\n');
					getline(cin, input);
					item->setDescription(input);
				}
				cout << "\nwould you like to change the item's type? [1]Yes [2]No ";
				if ((input = yesOrNo()) == "1")
				{
					/*Special* sPtr = dynamic_cast<Special*>(item);
					if (sPtr != NULL)
					{
						editSpecial(sPtr);
						return;
					}
					else
					{
						Edible* ePtr = dynamic_cast<Edible*>(item);
						if (ePtr != NULL)
						{
							editEdible(ePtr);
							return;
						}
						else
						{
							Beverage* bPtr = dynamic_cast<Beverage*>(item);
							if (ePtr != NULL)
							{
								editBeverage(bPtr);
								return;
							}
							else
								cerr << "There was a problem casting item..\n";
						}
					}*/
					
					BevType bArr[4] = { SoftDrink , HotDrink , Wine , Liqour };
					EdType eArr[4] = { Breakfast, Italian, Meat, Dessert };
					Special* sPtr = dynamic_cast<Special*>(item);
					if (sPtr != NULL)
					{
						cout << "please choose beverage type: [0] SoftDrink, [1] HotDrink, [2] Wine, [3] Liqour ";
						while (1)
						{
							input = getChoice();
							if (input == "0" || input == "1" || input == "2" || input == "3")
							{
								sPtr->Beverage::setType(bArr[atoi(input.c_str())]);
								cout << "please choose edible type: [0] Breakfast, [1] Italian, [2] Meat, [3] Dessert ";
								while (1)
								{
									input = getChoice();
									if (input == "0" || input == "1" || input == "2" || input == "3")
									{
										sPtr->Edible::setType(eArr[atoi(input.c_str())]);
										cout << "\n\nThe item was successfuly changed!\n\n";
										sPtr->printItem();
										return;
									}
									cout << "invalid number..";
								}
							}
							cout << "invalid number..";
						}
					}
					else
					{
						Beverage* bPtr = dynamic_cast<Beverage*>(item);
						if (bPtr != NULL)
						{
							cout << "please choose type: [0] SoftDrink, [1] HotDrink, [2] Wine, [3] Liqour ";
							while (1)
							{
								input = getChoice();
								if (input == "0" || input == "1" || input == "2" || input == "3")
								{
									bPtr->setType(bArr[atoi(input.c_str())]);
									cout << "\n\nThe item was successfuly changed!\n\n";
									bPtr->printItem();
									return;
								}
								cout << "invalid number..";
							}
						}
						else
						{
							Edible* ePtr = dynamic_cast<Edible*>(item);
							if (ePtr == NULL)
							{
								cerr << "There was a problam casting the item\n\n";
								return;
							}
							cout << "please choose type: [0] Breakfast, [1] Italian, [2] Meat, [3] Dessert ";

							while (1)
							{
								input = getChoice();
								if (input == "0" || input == "1" || input == "2" || input == "3")
								{
									ePtr->setType(eArr[atoi(input.c_str())]);
									cout << "\n\nThe item was successfuly changed!\n\n";
									ePtr->printItem();
									return;
								}
								cout << "invalid number..";
							}
						}
					}
				}
				else
				{
					cout << "The item was successfuly changed!\n\n";
					item->printItem();
					return;
				}
			}
			else
				cerr << "There's not such item ";
		}
	} while (1);
}
/*

void Restaurant::editSpecial(SharedPtr<Special> item) {

	BevType bArr[4] = { SoftDrink , HotDrink , Wine , Liqour };
	EdType eArr[4] = { Breakfast, Italian, Meat, Dessert };

	cout << "please choose beverage type: [0] SoftDrink, [1] HotDrink, [2] Wine, [3] Liqour ";
	while (1)
	{
		string input = getChoice();
		if (input == "0" || input == "1" || input == "2" || input == "3")
		{
			item->Beverage::setType(bArr[atoi(input.c_str())]);
			cout << "please choose edible type: [0] Breakfast, [1] Italian, [2] Meat, [3] Dessert ";
			while (1)
			{
				input = getChoice();
				if (input == "0" || input == "1" || input == "2" || input == "3")
				{
					item->Edible::setType(eArr[atoi(input.c_str())]);
					cout << "\n\nThe item was successfuly changed!\n\n";
					item->printItem();
					return;
				}
				cout << "invalid number..";
			}
		}
		cout << "invalid number..";
	}
}

void Restaurant::editEdible(SharedPtr<Edible> item) {

	EdType eArr[4] = { Breakfast, Italian, Meat, Dessert };
	cout << "please choose type: [0] Breakfast, [1] Italian, [2] Meat, [3] Dessert ";
	while (1)
	{
		string input = getChoice();
		if (input == "0" || input == "1" || input == "2" || input == "3")
		{
			item->setType(eArr[atoi(input.c_str())]);
			cout << "\n\nThe item was successfuly changed!\n\n";
			item->printItem();
			return;
		}
		cout << "invalid number..";
	}
}

void Restaurant::editBeverage(SharedPtr<Beverage> item) {

	BevType bArr[4] = { SoftDrink , HotDrink , Wine , Liqour };
	cout << "please choose type: [0] SoftDrink, [1] HotDrink, [2] Wine, [3] Liqour ";
	while (1)
	{
		string input = getChoice();
		if (input == "0" || input == "1" || input == "2" || input == "3")
		{
			item->setType(bArr[atoi(input.c_str())]);
			cout << "\n\nThe item was successfuly changed!\n\n";
			item->printItem();
			return;
		}
		cout << "invalid number..";
	}
}*/