#include "Table.h"

int Table::idCount = 0; //static member initialization

void Table::cashOut() {

	cout << setw(14) << left << "Name" << "Price\n---------------------\n";

	for (vector<SharedPtr<Item>>::const_iterator it = bill.getItemList().begin(); it != bill.getItemList().end(); ++it)
		cout << setw(15) << left << (*it)->getName() << (*it)->getPrice() << endl;
	cout << endl << "Total: " << bill.getTotal() << endl;
}


void Table::printTable() const {

	cout << setw(7) << left << tableID
		 << setw(7) << left << diners
		 << setw(7) << left << bill.getTotal();
		    bill.printItemList(); cout << "\n";
}
