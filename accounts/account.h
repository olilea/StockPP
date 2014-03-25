#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using std::string;

class Account {
	
public:
	void setName(string);
	void setCash(float);
	void addCash(float);

	string getName(void);
	float getCash(void);

private:
	string name;
	float cash;

};

#endif
