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
	static string output;

	static string getTicker(void);
	static string getUsername(void);
	static void logoutHandler(void);

};

#endif
