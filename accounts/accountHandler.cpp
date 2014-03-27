#include "accountHandler.h"
#include "account.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>

// At the bottom of this file is an example of a typical JSON file containing
// valid user data

using std::string;
using std::to_string;

using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::ios;

using std::stringstream;

using std::list;

using std::vector;

// Static declarations;
Account AccountHandler::loggedInAccount;
bool AccountHandler::loggedInStatus = false;
string AccountHandler::accountFilename;

bool AccountHandler::login(string accountName) {
	
	string accountData = readAccountFile();
	list<string> jsonTokens = getJsonTokens(accountData);
	
	if (accountPresent(jsonTokens, accountName)) {
		loggedInAccount = accountFromJson(jsonTokens, accountName);
	} else {
		return false;
	}

	setLoggedInStatus(true);
	return true;
}

bool AccountHandler::logout(void) {

	saveAccount();
	setLoggedInStatus(false);

	return true;
}

// Not clean - assumes the input string is valid JSON
bool AccountHandler::accountPresent(list<string> tokens, string accountName) {

	// Used if the Account is not the first in the file
	int braceCounter = 0;

	// Pop first curly brace
	tokens.pop_front();
	braceCounter++;

	// Pop inv comms, "Accounts", inv comms and colon
	for (int i = 0; i < 4; i++) {
		tokens.pop_front();
	}

	// Pop curly brace
	tokens.pop_front();
	braceCounter++;

	// Pop inv comms
	tokens.pop_front();

	if (tokens.front() == accountName) {
		return true;
	} else {
		// Not the correct user, check the rest

		// While not at the end of the file
		while (braceCounter != 0) {

			// Pop account name, inv comms and colon
			for (int i = 0; i < 3; i++) {
				tokens.pop_front();
			}

			// Pop curly brace
			tokens.pop_front();
			braceCounter++;

			// While still parsing not needed user
			while (braceCounter != 2) {
				if (tokens.front() ==  "{") {
					braceCounter++;
				} else if (tokens.front() == "}") {
					braceCounter--;
				}
				tokens.pop_front();
			}

			// Check for the account name again
			if (tokens.front() == ",") {
				tokens.pop_front();
				// Pop inv comms
				tokens.pop_front();

				if (tokens.front() == accountName) {
					return true;
				}

			// If another curly brace is found, no more users present.
			} else if (tokens.front() == "}") {
				return false;
			}
		}

		// Account not found
		return false;

	}
}

Account AccountHandler::accountFromJson(list<string> tokens, string accountName) {

	list<Stock> accountStock;
	float cash;

	string tempStockName;
	int tempStockAmount;

	while (tokens.front() != accountName) {
		tokens.pop_front();
	}

	// Pop account name, inverted commas, colon, curly brace, inv comms, "Cash", inv comms and colon
	for (int i = 0; i < 8; i++) {
		tokens.pop_front();
	}

	// Convert string to c_string and then call atof on the c_string
	cash = ::atof(tokens.front().c_str());

	// Pop cash, comma, inv comms, "Stocks", inv comms, colon and curly brace
	for (int i = 0; i < 7; i++) {
		tokens.pop_front();
	}

	while (tokens.front() != "}") {

		// Pop inv comms
		tokens.pop_front();
		tempStockName = tokens.front();

		// Pop ticker, inv comms and colon
		for (int i = 0; i < 3; ++i) {
			tokens.pop_front();
		}

		tempStockAmount = ::atoi(tokens.front().c_str());
		tokens.pop_front();

		// Remove comma if present
		if (tokens.front() == ",") {
			tokens.pop_front();
		}

		accountStock.push_back(Stock(tempStockName, tempStockAmount));
	}

	return Account(accountName, cash, accountStock);
}

// Not clean - assumes the input string is valid JSON
list<string> AccountHandler::getJsonTokens(string accountData) {

	list<string> tokens;

	string substring = "";

	int stringLength = accountData.length();


	for (int i = 0; i < stringLength; ++i) {

		// If a double quote is found and there are more characters
		if ((accountData.at(i) == '"') && ((i + 1) < stringLength)) {

			// Move to the next character
			i++;
			// Set the substring container to the empty string
			substring = "";

			// Push inverted commas token
			tokens.push_back("\"");

			// While the paired double quote is not found and there are more characters
			while (accountData.at(i) != '"') {
				substring += accountData.at(i);
				i++;

				if (i >= stringLength) {
					break;
				}
			}

			// Push this string into the token list
			tokens.push_back(substring);

			// Push inverted commas token
			tokens.push_back("\"");

		} else if ((accountData.at(i) >= '0') && (accountData.at(i) <= '9')) {
			// The character is a digit

			// Set the substring container to the empy string
			substring = "";

			// Add the first digit of the number to the substring
			substring += accountData.at(i);

			// While not at the end and the next digit is a number or a dot
			while (((i + 1) < stringLength) && ((accountData.at(i + 1) == '.') || 
					((accountData.at(i + 1) >= '0') && (accountData.at(i + 1) <= '9')))) {
				i++;
				substring += accountData.at(i);
			}

			tokens.push_back(substring);

		} else if (accountData.at(i) == '{') {
			tokens.push_back("{");
		} else if (accountData.at(i) == '}') {
			tokens.push_back("}");
		} else if (accountData.at(i) == ':') {
			tokens.push_back(":");
		} else if (accountData.at(i) == ',') {
			tokens.push_back(",");
		} else {
			continue;
		}
	}

	// Prints out the tokens collected
	/*
	for (list<string>::const_iterator y = tokens.begin(); y != tokens.end(); ++y) {
		cout << *y << " ";
	}
	cout << endl;
	*/

	return tokens;
}

bool AccountHandler::saveAccount(void) {

	string saveString = createNewSave();

	ofstream accountFileOut;
	accountFileOut.open(accountFilename, ios::trunc);

	accountFileOut << saveString;

	accountFileOut.close();

	return true;

}

string AccountHandler::createNewSave(void) {

	string newSave = "";

	list<string> fileJson = getJsonTokens(readAccountFile());
	list<string> accountJson = getJsonTokens(loggedInAccount.toJsonString());

	int sizeFileJson = fileJson.size();
	int sizeAccountJson = accountJson.size();

	cout << endl;

	int braceCounter = 0;

	// Remove first inv comm
	accountJson.pop_front();
	sizeAccountJson--;

	for (int i = 0; i < sizeFileJson; ++i) {

		if (fileJson.front() == loggedInAccount.getName()) {

			// Pop account name, inv comm, colon and curly brace
			for (int x = 0; x < 4; ++x) {
				fileJson.pop_front();
			}
			braceCounter++;

			// Remove previous account data
			while (braceCounter != 0) {

				if (fileJson.front() == "{") {
					braceCounter++;
				} else if (fileJson.front() == "}") {
					braceCounter--;
				}
				fileJson.pop_front();
			}

			// Add new account data
			for (int y = 0; y < sizeAccountJson; ++y) {
				newSave += accountJson.front();
				accountJson.pop_front();
			}

			// Break main loop
			break;

		} else {
			newSave += fileJson.front();
			fileJson.pop_front();
		}
	}

	sizeFileJson = fileJson.size();
	for (int z = 0; z < sizeFileJson; ++z) {
		newSave += fileJson.front();
		fileJson.pop_front();
	}

	return newSave;
}

string AccountHandler::readAccountFile(void) {

	ifstream accountFileIn;
	stringstream inputBuffer;

	accountFileIn.open(accountFilename);
	inputBuffer << accountFileIn.rdbuf();

	accountFileIn.close();

	return inputBuffer.str();

}

void AccountHandler::setupAccountFile(void) {

	ofstream accountFileOut;

	string input;

	// Open the file to append - create if it does not exit
	accountFileOut.open(accountFilename, ios::app);

	accountFileOut.close();

}

Account AccountHandler::getLoggedInAccount(void) {
	return loggedInAccount;
}

bool AccountHandler::getLoggedInStatus(void) {
	return loggedInStatus;
}

string AccountHandler::getAccountFilename(void) {
	return accountFilename;
}

void AccountHandler::setLoggedInStatus(bool status) {
	loggedInStatus = status;
}

void AccountHandler::setAccountFilename(string fileName) {
	accountFilename = fileName;
}

/*
{
  "Accounts": {
    "Oli": {
      "Cash": 50.0,
      "Stocks": {
        "AAPL": 4,
        "XOM": 10,
        "YHOO": 54
      }
    },
    "Dan": {
      "Cash": 1000,
      "Stocks": {
        "XOM": 15
      }
    }
  }
}
*/
