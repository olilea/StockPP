#include "stockPP.h"
#include "userInterface.h"

#include "accounts/accountHandler.h"

#include <iostream>
#include <string>

using std::string;

// Static declaration
UserInterface StockPP::ui;

int StockPP::begin(string accountFilename) {

	std::cout << "Using user database: " << accountFilename << std::endl;

	AccountHandler::setAccountFilename(accountFilename);
	AccountHandler::setupAccountFile();

	return ui.mainMenu();

}
