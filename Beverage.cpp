#include "Beverage.h"

string Beverage::getType(BevType e) const {

	if (e == 0)
		return "SoftDrink";
	else if (e == 1)
		return "HotDrink";
	else if (e == 2)
		return "Wine";
	else
		return "Liqour";
}