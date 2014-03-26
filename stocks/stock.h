#ifndef STOCK_H
#define STOCK_H

#include <string>

using std::string;

class Stock {
	
public:
	Stock(string);

	void setValue(float);
	
	string getTicker(void);
	float getValue(void);

private:
	string ticker;
	float value;

};

#endif
