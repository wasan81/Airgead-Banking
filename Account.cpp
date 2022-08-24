#include "Account.h"
Account::Account(string name, string address, int accountNumber, string accountType)
{
	this->name = name;
	this->address = address;
	this->accountNumber = accountNumber;
	this->accountType = accountType;
}

string Account::getName()
{
	return name;
}

string Account::getAddress()
{
	return address;
}

int Account::getAccountNumber()
{
	return accountNumber;
}

string Account::getAccountType()
{
	return accountType;
}

