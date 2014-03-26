#include "stockPP.h"
#include "userInterface.h"

#include "accounts/accountHandler.h"

#include <iostream>
#include <string>

using std::string;

// Static declarations
UserInterface StockPP::ui;

int StockPP::begin(string accountFilename) {

	std::cout << "Using user database: " << accountFilename << std::endl;

	AccountHandler::setAccountFilename(accountFilename);
	AccountHandler::setupAccountFile();

	return ui.mainMenu();

}

UserInterface StockPP::getUserInterface(void) {
	return ui;
}
