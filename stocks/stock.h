#ifndef STOCK_H
#define STOCK_H

#include <string>

using std::string;

class Stock {
	
public:
	Stock(string, int);

	void setValue(float);
	void setOwned(int);
	
	string getTicker(void);
	float getValue(void);
	int getOwned(void);

private:
	string ticker;
	float value;
	int owned;

};

#endif
