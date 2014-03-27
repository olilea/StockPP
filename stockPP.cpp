#include "stockPP.h"
#include "userInterface.h"

#include "accounts/accountHandler.h"

#include <iostream>
#include <string>

using std::string;

StockPP::StockPP(string accountFilename) {

	AccountHandler::setAccountFilename(accountFilename);
	AccountHandler::setupAccountFile();

	std::cout << "\nUsing user database: " << accountFilename << std::endl;

	UserInterface::mainMenu();
}
