#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "accountHandler.h"
#include "account.h"

using std::string;

using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::ios;

using std::stringstream;

// Static declarations;
Account AccountHandler::loggedInAccount;
bool AccountHandler::loggedInStatus = false;
string AccountHandler::accountFilename;

int AccountHandler::login(string accountName) {
	setLoggedInStatus(true);
	return 0;
}

int AccountHandler::logout(void) {
	setLoggedInStatus(false);

	return 0;
}

string AccountHandler::readAccountFile(void) {

	ifstream accountFileIn;
	stringstream inputBuffer;

	accountFileIn.open(accountFilename);
	inputBuffer << accountFileIn.rdbuf();

	accountFileIn.close();

	return inputBuffer.str();

}

void AccountHandler::setupAccountFile(void) {

	ofstream accountFileOut;

	string input;

	// Open the file to append - create if it does not exit
	accountFileOut.open(accountFilename, ios::app);

	accountFileOut.close();

}

Account AccountHandler::getLoggedInAccount(void) {
	return loggedInAccount;
}

bool AccountHandler::getLoggedInStatus(void) {
	return loggedInStatus;
}

string AccountHandler::getAccountFilename(void) {
	return accountFilename;
}

void AccountHandler::setLoggedInStatus(bool status) {
	loggedInStatus = status;
}

void AccountHandler::setAccountFilename(string fileName) {
	accountFilename = fileName;
}
