#include "ui.h"

void userMenu() {

	cout << "                 _ _   _                    _                              _   \n"
		<< "                (_| | ( )                  | |                            | |  \n"
		<< "  __ _ _ __ ___  _| |_|/ ___   _ __ ___ ___| |_ __ _ _   _ _ __ __ _ _ __ | |_ \n"
		<< " / _` | '_ ` _ \\| | __| / __| | '__/ _ / __| __/ _` | | | | '__/ _` | '_ \\| __|\n"
		<< "| (_| | | | | | | | |_  \\__ \\ | | |  __\\__ | || (_| | |_| | | | (_| | | | | |_ \n"
		<< " \\__,_|_| |_| |_|_|\\__| |___/ |_|  \\___|___/\\__\\__,_|\\__,_|_|  \\__,_|_| |_|\\__|\n"
		<< "\nWhat would you like to do?\n"
		<< "[1] Add a new table\n"
		<< "[2] Make an order\n"
		<< "[3] Look at the menu\n"
		<< "[4] Print today's sales\n"
		<< "[5] Pay a table's bill\n"
		<< "[6] Change an item\n"
		<< "[7] Exit\n\n";
}

void goodByeMsg() {

	cout << "\nHope you had a blast!\n"
		 << "Good Bye..\n";
	cin.ignore(10000, '\n');
	getchar();
}

void pause() {

	cout << "\npress ENTER to continue ";
	cin.ignore(10000, '\n');
	getchar();
}

bool isNumber(const string& s) {

	for (string::const_iterator it = s.begin(); it != s.end(); ++it)
		if (!isdigit(*it))
			return false;
	return true;
}

string getChoice() {

	do {

		cin >> input;
		if ((!isNumber(input)))
			cerr << "please enter numbers only ";

	} while ((!isNumber(input)));
	return input;
}

string yesOrNo() {

	bool b;
	do {

		b = false;
		cin >> input;
		if ((!isNumber(input)) || (input != "1" && input != "2"))
		{
			cerr << "invalid option, please try again ";
			b = true;
		}

	} while (b);
	return input;
}

string getChoiceMain() {

	bool b;
	do {

		b = false;
		cin >> input;
		if ((!isNumber(input)) || (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "7"))
		{
			cerr << "invalid option, please try again ";
			b = true;
		}
			
	} while (b);
	return input;
}


void Case1(Restaurant& r) { //adding a new table, can then make an order

	if (r.tablesNumber() == 10)
	{
		cout << "We're full at the moment, please come back later..\n";
		pause(); return;
	}

	cout << "How many diners will u be? ";
	do //getting input
	{
		int diners = atoi(getChoice().c_str());
		if (diners > 10 || diners < 1)
			cerr << "diners number can only be 1 - 10\nplease try again ";
		else
		{
			r.addTable(diners); //adding the table
			break;
		}

	} while (1);

	cout << "would you like to order now?\n[1]Yes\n[2]No\n";
	do 
	{
		input = getChoice();
		if (input == "1") //wants to order
		{
			r.order(r.getLastTable()); //ordering to the last table added
			return;
		}
		else if (input == "2") //doesnt want to order
		{
			pause();
			return;
		}
		cerr << "there's not such option ";

	} while (1);
}


void Case2(Restaurant& r) { //make an order to an existing table

	if (r.isEmpty())
	{
		cerr << "there are not tables in the restaurant yet\n";
		pause();
		return;
	}

	Table* tablePtr;
	r.printTables();
	cout << "please choose a table ";
	do 
	{
		input = getChoice();
		if ((tablePtr = r.findTable(atoi(input.c_str()))) != NULL) //searching the table and pointing to it with tablePtr
		{
			r.order(tablePtr); //found, make an order
			return;
		}
		else
			cout << "there's not such table "; //table was not found
	} while (1);
}


void Case5(Restaurant& r) { //paying a table

	if (r.isEmpty())
	{
		cerr << "there are not tables in the restaurant yet\n";
		pause();
		return;
	}

	r.printTables();
	Table* tablePtr;
	cout << "which table's bill would you like to pay? ";
	do 
	{
		input = getChoice();
		if ((tablePtr = r.findTable(atoi(input.c_str()))) == NULL) //searching the table and pointing to it with tablePtr
			cerr << "there's not such table ";
		else
		{
			cout << "\n\nHere is your bill::\n\n";
			tablePtr->cashOut();
			r.removeTable(tablePtr);
			cout << "\ntable was successfuly checked out\n";
			pause();
			return;
		}
	} while (1);
}