#include "account.h"

#include "../stocks/stock.h"

#include <string>
#include <list>

using std::string;

using std::list;
using std::to_string;

Account::Account(void) {
	// Empty default constructor
}

Account::Account(string accountName, float cashHeld, list<Stock> listOfStock) {
	name = accountName;
	cash = cashHeld;
	stocksHeld = listOfStock;
}

string Account::toString(void) {

	string accountString = "";
	list<Stock> stocks = stocksHeld;
	int numOfStocks = stocks.size();

	accountString += name + "\n";
	accountString += "Cash Held: " + to_string(cash) + "\n";

	accountString += "Stocks Held:\n";

	while (numOfStocks != 0) {
		accountString += stocks.front().getTicker() + " ";
		accountString += to_string(stocks.front().getOwned()) + "\n";
		stocks.pop_front();

		numOfStocks--;
	}

	return accountString;
}

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

