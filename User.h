
#ifndef USER_H
#define USER_H

#include <string>

using std::string;

class User {
	
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
