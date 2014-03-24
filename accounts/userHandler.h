#ifndef USERHANDLER_H
#define USERHANDLER_H

#include <string>

using std::string;

class User;

class UserHandler {

public:
	static int login(string);
	static int logout(void);
	static string readUserFile(void);
	static void setupUserFile(void);

	static User getLoggedInUser(void);
	static bool getLoggedInStatus(void);
	static string getUserFilename(void);

	static void setLoggedInStatus(bool);
	static void setUserFilename(string);

private:
	static User loggedInUser;
	static bool loggedInStatus;
	static string userFilename;

};

#endif
