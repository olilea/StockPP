#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>

using std::string;

class UserInterface {

public:
	static void mainMenu(void);
	static void menuChoices(void);

private:
	static string input;

	static string getLoginInfo(void);
	static void logoutHandler(void);

};

#endif
