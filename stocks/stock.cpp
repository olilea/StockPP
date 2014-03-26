#include "stock.h"

#include <string>

using std::string;

Stock::Stock(string tickerName) {
	ticker = tickerName;
}

void Stock::setValue(float newValue) {
	value = newValue;
}

string Stock::getTicker(void) {
	return ticker;
}

float Stock::getValue(void) {
	return value;
}
