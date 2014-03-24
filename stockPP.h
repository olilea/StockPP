#ifndef STOCKPP_H
#define STOCKPP_H

#include <string>

using std::string;

class UserInterface;

class StockPP {
	
public:
	static int begin(string userFilename = "userData.json");

	static UserInterface getUserInterface(void);

private:
	static UserInterface ui;

};

#endif
