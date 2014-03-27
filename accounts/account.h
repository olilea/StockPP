#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "../stocks/stock.h"

#include <string>
#include <list>

using std::string;

using std::list;

class Account {
	
public:

	// Default constructor
	Account(void);

	Account(string, float, list<Stock>);

	string toString(void);
	string toJson(void);

	void setName(string);
	void setCash(float);
	void addCash(float);

	string getName(void);
	float getCash(void);
	list<Stock> getStocksHeld(void);

private:
	string name;
	float cash;
	list<Stock> stocksHeld;
};

#endif
