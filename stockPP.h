#ifndef STOCKPP_H
#define STOCKPP_H

class UserInterface;

class StockPP {
	
public:
	static int begin(void);

	static UserInterface getUserInterface(void);

private:
	static UserInterface ui;

};

#endif
