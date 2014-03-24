#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>

using std::string;

class UserInterface {

public:
	int mainMenu(void);
	void menuChoices(void);

private:
	string input;

	void fetchLoginInfo(void);
	void logoutHandler(void);

};

#endif
