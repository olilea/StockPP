#include "StockPP.h"
#include "UserInterface.h"

// Static declarations
UserInterface StockPP::ui;

int StockPP::begin(void) {

	return ui.mainMenu();

}

UserInterface StockPP::getUserInterface(void) {
	return ui;
}
