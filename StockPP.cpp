#include "StockPP.h"

bool StockPP::loggedIn = false;

int StockPP::begin(void) {

	ui.mainMenu();

	return 0;
}

UserInterface StockPP::getUserInterface(void) {
	return ui;
}

bool StockPP::getLoggedIn(void) {
	return loggedIn;
}
