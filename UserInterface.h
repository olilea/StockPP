#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <string>

class UserInterface {

public:
	int mainMenu(void);
	void menuChoices(void);

private:
	std::string input;

	void fetchLoginInfo(void);
	void logoutHandler(void);

};

#endif
