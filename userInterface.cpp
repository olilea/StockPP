#include "userInterface.h"

#include "accounts/accountHandler.h"

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string UserInterface::input;

void UserInterface::mainMenu(void) {

	bool chosen = false;

	if (!AccountHandler::getLoggedInStatus()) {
		cout << "YOU ARE NOT LOGGED IN - Login using the menu below" << endl;
	}

	while (1) {

		menuChoices();
		cin >> input;
		cout << endl;

		while (!chosen) {

			switch (input[0]) {

				case '1':
					cout << "It works" << endl;
					chosen = true;
					break;

				case '2':
					if (AccountHandler::getLoggedInStatus()) {
						cout << AccountHandler::getLoggedInAccount().toString() << endl;
					} else {
						cout << "You are not logged in...\n" << endl;
					}
					chosen = true;
					break;

				case '3':
					chosen = true;
					break;

				case '4':
					chosen = true;
					break;

				case '5':
					if (AccountHandler::getLoggedInStatus()) {
						// If logged in
						logoutHandler();
					} else {
						// If not logged in
						if (AccountHandler::login(fetchLoginInfo())) {
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
				default:
					cout << "Incorrect choice - Choose again..." << endl;
					cin >> input;
			}
		}
		chosen = false;
	}
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

	cout << "6: Exit\n" << endl;
}

string UserInterface::fetchLoginInfo(void) {

	string username;

	cout << "Please enter your username:" << endl;

	cin >> username;

	return username;
}

void UserInterface::logoutHandler(void) {
	AccountHandler::logout();
}
