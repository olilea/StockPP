#include "userInterface.h"

#include "accounts/accountHandler.h"

#include "stocks/stockHandler.h"

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::getline;

using std::string;

string UserInterface::input;
string UserInterface::output;
string UserInterface::scratch;

void UserInterface::mainMenu(void) {

	bool chosen = false;

	while (1) {

		// Clear the entire display window and move the cursor to the topleftmost position
		cout << CLEAR_SCREEN;

		if (!AccountHandler::getLoggedInStatus()) {
			cout << "YOU ARE NOT LOGGED IN - Login using the menu below" << endl;
		}

		menuChoices();
		cin >> input;
		cout << endl;

		while (!chosen) {

			switch (input[0]) {

				case '1':
					lookupStockHandler();
					chosen = true;
					break;

				case '2':
					if (AccountHandler::getLoggedInStatus()) {
						cout << AccountHandler::getLoggedInAccount()->toString() << endl;
					} else {
						cout << "You are not logged in...\n" << endl;
					}
					chosen = true;
					break;

				case '3':
					if (AccountHandler::getLoggedInStatus()) {
						buyStockHandler();
					} else {
						cout << "You are not logged in...\n" << endl;
					}
					chosen = true;
					break;

				case '4':
					if (AccountHandler::getLoggedInStatus()) {
						sellStockHandler();
					} else {
						cout << "You are not logged in...\n" << endl;
					}
					chosen = true;
					break;

				case '5':
					if (AccountHandler::getLoggedInStatus()) {
						// If logged in
						logoutHandler();
					} else {
						// If not logged in
						if (AccountHandler::login(getUsername())) {
							cout << "Login successful...\n" << endl;
						} else {
							cout << "Error - Could not find account\n" << endl;
						}
					}
					chosen = true;
					break;

				case '6':
					chosen = true;
					return;
					break;

				case '7':
					if (!AccountHandler::getLoggedInStatus()) {
						AccountHandler::login(getUsername());
						chosen = true;
						break;
					}
					// Else, drop down to default as the option is not available
				default:
					cout << "Incorrect choice - Choose again..." << endl;
					cin >> input;
			}
		}
		cout << "Press RETURN to continue..." << endl;
		// Once simply uses the last return in the buffer, twice waits for a new one
		cin.get();
		cin.get();
		chosen = false;
	}
}

void UserInterface::test() {
	
	list<string> stockTokens = StockHandler::lexStockData(StockHandler::getStockData("AAPL"));

	cout << (StockHandler::getNameToken(stockTokens)) << endl;
}

void UserInterface::menuChoices(void) {

	cout << "Main Menu:" << endl;

	cout << "1: Lookup stock by ticker\n"
			<< "2: View stock in portfolio\n"
			<< "3: Buy stock\n"
			<< "4: Sell stock\n";

	if (AccountHandler::getLoggedInStatus()) {
		cout << "5: Logout\n";
	} else {
		cout << "5: Login\n";
	}

	cout << "6: Exit" << endl;

	if (!AccountHandler::getLoggedInStatus()) {
		cout << "7: Create new account" << endl;
	}
}

string UserInterface::getTicker(void) {

	string ticker;

	cout << "Please enter the ticker of the stock:" << endl;
	cin >> ticker;
	cout << endl;

	return ticker;
}

string UserInterface::getUsername(void) {

	string username;

	cout << "Please enter your username:" << endl;
	cin >> username;
	cout << endl;

	return username;
}

float UserInterface::getAmount(void) {

	float amount;

	cout << "Please enter the amount:" << endl;
	cin >> amount;
	cout << endl;

	return amount;
}

// Fetches stock data, parses it and prints it
void UserInterface::lookupStockHandler(void) {
	string ticker = getTicker();
	list<string> stockTokens = StockHandler::lexStockData(StockHandler::getStockData(ticker));

	if (StockHandler::stockExists(stockTokens)) {
		cout << StockHandler::toPrettyString(stockTokens) << endl;
	} else {
		cout << "This stock does not exist...\n" << endl;
	}
}

void UserInterface::buyStockHandler(void) {
	string ticker = getTicker();
	list<string> stockTokens = StockHandler::lexStockData(StockHandler::getStockData(ticker));
	float latest = StockHandler::getLatestToken(stockTokens);

	if (StockHandler::stockExists(stockTokens)) {


		if (AccountHandler::getLoggedInAccount()->ownStock(ticker)) {
			cout << "You already own " << AccountHandler::getLoggedInAccount()->getStock(ticker).getOwned()
				<< " shares of this stock" << endl;
		}

		cout << StockHandler::toPrettyString(stockTokens) << endl;
		if (AccountHandler::getLoggedInAccount()->getCash() >= latest) {

			float amountToBuy = getAmount();

			if ((AccountHandler::getLoggedInAccount()->getCash()) >= (amountToBuy * latest)) {

				AccountHandler::getLoggedInAccount()->subtractCash(amountToBuy * latest);
				AccountHandler::getLoggedInAccount()->addStock(ticker, amountToBuy);
				return;
			}
		}
		cout << "You do not have the funds to purchase this stock..." << endl;

	} else {
		cout << "This stock does not exist...\n" << endl;
	}
}

void UserInterface::sellStockHandler(void) {
	string ticker = getTicker();
	list<string> stockTokens = StockHandler::lexStockData(StockHandler::getStockData(ticker));

	if (StockHandler::stockExists(stockTokens)) {

		// TODO
	}
}

void UserInterface::logoutHandler(void) {
	AccountHandler::logout();
}
