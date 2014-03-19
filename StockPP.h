#ifndef STOCKPP_H
#define STOCKPP_H

#include "UserInterface.h"

class StockPP {
	
	private:
		UserInterface ui;

	public:
		int begin(void);
		UserInterface getUserInterface(void);
};

#endif
