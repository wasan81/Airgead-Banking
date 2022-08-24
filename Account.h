#pragma once

#include <string>
#include <cmath>
#include "DoubleWrapper.h"

using namespace std;

class Account
{
public:
	Account(string name, string address, int accountNumber, string accountType);
	virtual double getEndingBalance(int numberOfYears) = 0;
	virtual double getInterestEarned(int numberOfYears) = 0;
	virtual string getAccountDetails() = 0;
	string getName();
	string getAddress();
	int getAccountNumber();
	string getAccountType();


private:
	string name;
	string address;
	int accountNumber;
	string accountType;	

};

