#include "StockPP.h"

StockPP::StockPP(void) {
	return;
}

int StockPP::begin(void) {
	//cout << "Hello, world, but ++" << endl;

	userI.mainMenu();

	return 0;
}

UserI StockPP::getUserI(void) {
	return userI;
}
