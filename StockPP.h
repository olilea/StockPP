#ifndef STOCKPP_H
#define STOCKPP_H

#include "UserInterface.h"

class StockPP {
	
public:
	int begin(void);

	UserInterface getUserInterface(void);


private:
	UserInterface ui;

};

#endif
