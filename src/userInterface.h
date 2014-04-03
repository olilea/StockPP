#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#define CLEAR_SCREEN "\033[2J\033[H"

#include <string>

using std::string;

class UserInterface {

public:
	static void mainMenu(void);
	static void menuChoices(void);

private:
	static string input;
	static string output;
	static string scratch;

	static void test(void);

	static string getTicker(void);
	static string getUsername(void);
	static float getAmount(void);

	static void lookupStockHandler(void);
	static void buyStockHandler(void);
	static void sellStockHandler(void);
	static void logoutHandler(void);

};

#endif
