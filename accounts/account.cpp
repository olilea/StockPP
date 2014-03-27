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

	accountString += "Name:\t\t" + name + "\n";
	accountString += "Cash:\t\t" + to_string(cash) + "\n";

	accountString += "Stocks:";

	while (numOfStocks != 0) {
		accountString += "\t\t" + stocks.front().getTicker();
		accountString += "\t" + to_string(stocks.front().getOwned()) + "\n";
		stocks.pop_front();

		numOfStocks--;
	}

	return accountString;
}

string Account::toJsonString(void) {

	string jsonString = "";
	list<Stock> stocks = stocksHeld;
	int numOfStocks = stocks.size();

	jsonString += "\"" + name + "\"" + ": { \"Cash\": " + to_string(cash) + ", \"Stocks\": { ";

	if (numOfStocks != 0) {
		while (numOfStocks != 1) {
			jsonString += "\"" + stocks.front().getTicker() + "\": " + to_string(stocks.front().getOwned()) + ", ";
			stocks.pop_front();

			numOfStocks--;
		}
		jsonString += "\"" + stocks.front().getTicker() + "\": " + to_string(stocks.front().getOwned());
	}
	
	jsonString += " } }";

	return jsonString;
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

