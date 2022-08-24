#pragma once
#include "Account.h"

class InvestmentAccount : public Account
{

public:
	InvestmentAccount(string name, string address, int accountNumber, 
		DoubleWrapper* initialAmount, DoubleWrapper* annualInterestRate);//set the monthlyDeposit to 0
	InvestmentAccount(string name, string address, int accountNumber,
		DoubleWrapper* initialAmount, DoubleWrapper* annualInterestRate, DoubleWrapper* monthlyDeposit);

	//inherited methods from Account
	virtual double getEndingBalance(int numberOfYears);
	virtual double getInterestEarned(int numberOfYears);
	virtual string getAccountDetails();

	DoubleWrapper* getInitialAmount();
	DoubleWrapper* getMonthlyDeposit();
	DoubleWrapper* getAnnualInterestRate();


private:
	DoubleWrapper* initialAmount;
	DoubleWrapper* monthlyDeposit;
	DoubleWrapper* annualInterestRate;

};

