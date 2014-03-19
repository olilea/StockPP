#include "UserInterface.h"

using std::cout;
using std::cin;
using std::endl;

void UserInterface::mainMenu(void) {

	cout << "Main Menu:\n\rPlease make your selection from below\n" << endl;

	cin >> input;

	cout << "\nYou typed: " << input << endl;
}
