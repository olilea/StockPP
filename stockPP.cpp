#include <iostream>
#include <string>

#include "stockPP.h"
#include "userInterface.h"

#include "accounts/userHandler.h"

using std::string;

// Static declarations
UserInterface StockPP::ui;

int StockPP::begin(string userFilename) {

	std::cout << "Using user database: " << userFilename << std::endl;

	UserHandler::setUserFilename(userFilename);
	UserHandler::setupUserFile();

	return ui.mainMenu();

}

UserInterface StockPP::getUserInterface(void) {
	return ui;
}
