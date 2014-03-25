#include <string>

#include "account.h"

using std::string;

void Account::setName(string newName) {
	name = newName;
}

void Account::setCash(float newCash) {
	cash = newCash;
}

void Account::addCash(float cashToAdd) {
	cash += cashToAdd;
}

string Account::getName(void) {
	return name;
}

float Account::getCash(void) {
	return cash;
}
