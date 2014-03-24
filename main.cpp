#include <iostream>
#include <string>

#include "StockPP.h"

using std::string;

int main(int argc, const char *argv[]) {

	if (argc == 1) {

		// If the user does not specify a specific user file
		return StockPP::begin();
	} else {

		// If the user uses their own user file

		string userFilename;
		userFilename += argv[1];

		return StockPP::begin(userFilename);
	}
}

