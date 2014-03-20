
#include "User.h"

using std::string;

void User::setName(string newName) {
	name = newName;
}

void User::setCash(float newCash) {
	cash = newCash;
}

void User::addCash(float cashToAdd) {
	cash += cashToAdd;
}

string User::getName(void) {
	return name;
}

float User::getCash(void) {
	return cash;
}
