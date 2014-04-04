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
	accountString += "Cash:\t\t$ " + to_string(cash) + "\n";

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

void Account::addCash(float cashToAdd) {
	cash += cashToAdd;
}

void Account::subtractCash(float cashToSubtract) {
	cash -= cashToSubtract;
}

void Account::addStock(string stockTicker, int quantityToAdd) {
	
	// If the stock is already in the stocksHeld array, update the amount held
	for (list<Stock>::iterator i = stocksHeld.begin(); i != stocksHeld.end(); ++i) {

		if (i->getTicker() == stockTicker) {
			i->addOwned(quantityToAdd);
			return;
		}
	}

	// Otherwise, add a new stock to stocksHeld
	stocksHeld.push_back(Stock(stockTicker, quantityToAdd));
}

void Account::subtractStock(string stockTicker, int quantityToRemove) {

	for (list<Stock>::iterator i = stocksHeld.begin(); i != stocksHeld.end(); ++i) {

		if (i->getTicker() == stockTicker) {
			i->subtractOwned(quantityToRemove);

			if (i->getOwned() == 0) {
				removeStock(stockTicker);
			}

			break;
		}
	}
}

void Account::removeStock(string stockTicker) {

	for (list<Stock>::iterator i = stocksHeld.begin(); i != stocksHeld.end(); ++i) {

		if (i->getTicker() == stockTicker) {

			// Move to the next Stock so the previous one can be removed
			stocksHeld.erase(i++);
			break;
		}
	}
}

bool Account::ownStock(string ticker) {

	for (list<Stock>::iterator i = stocksHeld.begin(); i != stocksHeld.end(); ++i) {
		if (i->getTicker() == ticker) {
			return true;
		}
	}
	return false;
}

Stock Account::getStock(string ticker) {
	
	for (list<Stock>::iterator i = stocksHeld.begin(); i != stocksHeld.end(); ++i) {
		if (i->getTicker() == ticker) {
			return (*i);
		}
	}
	// Should not reach this point
	return Stock("Error", 0);
}

void Account::setName(string newName) {
	name = newName;
}

void Account::setCash(float newCash) {
	cash = newCash;
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
