/** 
 * Restaurant C++ Project
 * made by Amit Shmuel - 305213621 
 */

#include "ui.h"

int main()
{
	Restaurant res;
	bool term = true;
	do {
		userMenu(); //prints the user menu
		switch (atoi(getChoiceMain().c_str())) //returns user choice as a string
		{
		case 1: //adding a new table, can then make an order
			Case1(res);
			break;
		case 2: //make an order to an existing table
			Case2(res);
			break;
		case 3: //prints the restaurant's menu
			res.printMenu(); pause();
			break;
		case 4: //prints today's sales
			res.printSales(); pause();
			break;
		case 5: //paying a table
			Case5(res);
			break;
		case 6: //edit an item
			res.editItem(); pause();
			break;
		case 7: //finish
			goodByeMsg();
			term = false;
		}
		system("cls||clear");
	} while (term);
	return 0;
}