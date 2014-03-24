#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "userHandler.h"
#include "user.h"

using std::string;

using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::ios;

using std::stringstream;

// Static declarations;
User UserHandler::loggedInUser;
bool UserHandler::loggedInStatus = false;
string UserHandler::userFilename;

int UserHandler::login(string username) {
	setLoggedInStatus(true);
	return 0;
}

int UserHandler::logout(void) {
	setLoggedInStatus(false);

	return 0;
}

string UserHandler::readUserFile(void) {

	ifstream userFileIn;
	stringstream inputBuffer;

	userFileIn.open(userFilename);
	inputBuffer << userFileIn.rdbuf();

	userFileIn.close();

	return inputBuffer.str();

}

void UserHandler::setupUserFile(void) {

	ofstream userFileOut;

	string input;

	// Open the file to append - create if it does not exit
	userFileOut.open(userFilename, ios::app);

	userFileOut.close();

}

User UserHandler::getLoggedInUser(void) {
	return loggedInUser;
}

bool UserHandler::getLoggedInStatus(void) {
	return loggedInStatus;
}

string UserHandler::getUserFilename(void) {
	return userFilename;
}

void UserHandler::setLoggedInStatus(bool status) {
	loggedInStatus = status;
}

void UserHandler::setUserFilename(string fileName) {
	userFilename = fileName;
}
