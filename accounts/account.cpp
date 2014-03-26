#include "account.h"

#include "../stocks/stock.h"

#include <string>
#include <list>

using std::string;

using std::list;

void Account::setName(string newName) {
	name = newName;
}

void Account::setCash(float newCash) {
	cash = newCash;
}

void Account::addCash(float cashToAdd) {
	cash += cashToAdd;
}

string Account::getName(void) {
	return name;
}

float Account::getCash(void) {
	return cash;
}

list<Stock> Account::getStocksHeld(void) {
	return stocksHeld;
}

