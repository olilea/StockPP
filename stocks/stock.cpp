#include "stock.h"

#include <string>

using std::string;

Stock::Stock(string tickerName, int stockOwned) {
	ticker = tickerName;
	owned = stockOwned;
}

void Stock::setOwned(int stockOwned) {
	owned = stockOwned;
}

string Stock::getTicker(void) {
	return ticker;
}

int Stock::getOwned(void) {
	return owned;
}
