#include "UserInterface.h"

#include "UserHandler.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int UserInterface::mainMenu(void) {

	bool chosen = false;

	if (!UserHandler::getLoggedInStatus()) {
		cout << "YOU ARE NOT LOGGED IN - Login using the menu below\n" << endl;
	}

	while (1) {

		menuChoices();
		cin >> input;

		while (!chosen) {

			switch (input[0]) {

				case '1':
					cout << "It works" << endl;
					chosen = true;
					break;

				case '2':
					chosen = true;
					break;

				case '3':
					chosen = true;
					break;

				case '4':
					chosen = true;
					break;

				case '5':
					if (UserHandler::getLoggedInStatus()) {
						logoutHandler();
					} else {
						fetchLoginInfo();
					}
					chosen = true;
					break;

				case '6':
					chosen = true;
					return 0;
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

	cout << "Main Menu:\n\rPlease make your selection from below\n" << endl;

	cout << "1: Lookup stock by ticker\n"
			<< "2: View stock in portfolio\n"
			<< "3: Buy stock\n"
			<< "4: Sell stock\n";

	if (UserHandler::getLoggedInStatus()) {
		cout << "5: Logout\n";
	} else {
		cout << "5: Login\n";
	}

	cout << "6: Exit\n" << endl;
}

void UserInterface::fetchLoginInfo(void) {

	string username;

	cout << "Please enter your username:" << endl;

	cin >> username;

	UserHandler::login(username);

}

void UserInterface::logoutHandler(void) {
	UserHandler::logout();
}
