#include "Edible.h"

string Edible::getType(EdType e) const {

	if (e == 0)
		return "Breakfast";
	else if (e == 1)
		return "Italian";
	else if (e == 2)
		return "Meat";
	else
		return "Dessert";
}