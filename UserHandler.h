#ifndef USERHANDLER_H
#define USERHANDLER_H

#include <string>

#include "User.h"

class UserHandler {

public:
	static int login(std::string);
	static int logout(void);

	static User getLoggedInUser(void);
	static bool getLoggedInStatus(void);

	static void setLoggedInStatus(bool);

private:
	static User loggedInUser;
	static bool loggedInStatus;

};

#endif
