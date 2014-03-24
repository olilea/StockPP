#include "UserHandler.h"
#include "User.h"

#include <string>

using std::string;

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
