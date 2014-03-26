#include "stock.h"

#include <string>

using std::string;

Stock::Stock(string tickerName, int stockOwned) {
	ticker = tickerName;
	owned = stockOwned;
}

void Stock::setValue(float newValue) {
	value = newValue;
}

void Stock::setOwned(int stockOwned) {
	owned = stockOwned;
}

string Stock::getTicker(void) {
	return ticker;
}

float Stock::getValue(void) {
	return value;
}

int Stock::getOwned(void) {
	return owned;
}
