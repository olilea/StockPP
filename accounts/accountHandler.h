#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H

#include <string>

using std::string;

class Account;

class AccountHandler {

public:
	static int login(string);
	static int logout(void);
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
