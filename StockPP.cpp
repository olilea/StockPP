#include "StockPP.h"

int StockPP::begin(void) {

	ui.mainMenu();

	return 0;
}

UserInterface StockPP::getUserInterface(void) {
	return ui;
}
