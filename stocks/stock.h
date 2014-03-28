#ifndef STOCK_H
#define STOCK_H

#include <string>

using std::string;

class Stock {
	
public:
	Stock(string, int);

	void subtractOwned(int);

	void setOwned(int);
	
	string getTicker(void);
	int getOwned(void);

private:
	string ticker;
	int owned;

};

#endif
