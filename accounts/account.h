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
	string toJsonString(void);

	void addCash(float);
	void subtractCash(float);

	void addStock(string, int);
	void subtractStock(string, int);
	void removeStock(string);
	bool ownStock(string ticker);
	Stock getStock(string ticker);

	void setName(string);
	void setCash(float);

	string getName(void);
	float getCash(void);
	list<Stock> getStocksHeld(void);

private:
	string name;
	float cash;
	list<Stock> stocksHeld;
};

#endif
