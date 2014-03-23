#ifndef STOCKPP_H
#define STOCKPP_H

#include "UserInterface.h"

class StockPP {
	
public:
	int begin(void);

	UserInterface getUserInterface(void);
	static bool getLoggedIn(void);

private:
	UserInterface ui;
	static bool loggedIn;

};

#endif
