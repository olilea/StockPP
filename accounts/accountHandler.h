#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H

#include <string>
#include <list>

using std::string;
using std::list;

class Account;

class AccountHandler {

public:
	static bool login(string);
	static bool logout(void);

	static Account accountFromJson(string, string);
	static bool accountPresent(string, string);

	static list<string> getJsonTokens(string);
	static string readAccountFile(void);
	static void setupAccountFile(void);

	static Account getLoggedInAccount(void);
	static bool getLoggedInStatus(void);
	static string getAccountFilename(void);

	static void setLoggedInStatus(bool);
	static void setAccountFilename(string);

private:
	static Account loggedInAccount;
	static bool loggedInStatus;
	static string accountFilename;

};

#endif
