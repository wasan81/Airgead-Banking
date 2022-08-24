#include "InvestmentAccount.h"
#include"DoubleWrapper.h"
#include"Account.h"
//Implementation for InvestmentAccount

InvestmentAccount::InvestmentAccount(string name, string address, int accountNumber,  DoubleWrapper* initialAmount,
	DoubleWrapper * annualInterestRate):

// CALL THE PARENT CONSTRUCTOR 
	Account(name, address,  accountNumber, "Investment-Compound; Without Monthly Deposit"){

	this->monthlyDeposit = new DoubleWrapper("0.00");// set monthly deposit to 0
	this->annualInterestRate = annualInterestRate;
	this->initialAmount = initialAmount;
	
	
}

InvestmentAccount::InvestmentAccount(string name, string address, int accountNumber , DoubleWrapper* initialAmount,
	DoubleWrapper* annualInterestRate, DoubleWrapper* monthlyDeposit):
	Account(name, address, accountNumber, "Investment-Compound; With Monthly Deposit")
{
	this->monthlyDeposit = monthlyDeposit;
	this->annualInterestRate = annualInterestRate;
	this->initialAmount = initialAmount;
}

double InvestmentAccount::getEndingBalance(int numberOfYears)
{
	
	double totalBalance = initialAmount->getValue();
	double InterestEarned;
	// for loop to get Ending Balance
	for (int i = 1; i <= numberOfYears * 12; ++i) {

		totalBalance += monthlyDeposit->getValue();
		InterestEarned = totalBalance * (annualInterestRate->getValue() / 100) / 12;
		totalBalance += InterestEarned;
		}
	return totalBalance;
}

double InvestmentAccount::getInterestEarned(int numberOfYears)

{
	
	double initil = initialAmount->getValue();
	double month = monthlyDeposit->getValue();
	double interestEarned;
	double annul = annualInterestRate->getValue();

	for (int i = 0; i <= numberOfYears * 12; ++i) {
		interestEarned = getEndingBalance(numberOfYears);
		
	}return interestEarned - initil;
}
	


string InvestmentAccount::getAccountDetails()
{
	
	string accountDetails = "Initial Amount: $" + initialAmount->getString(2);
	
	if (monthlyDeposit->getValue() > 0) {

		accountDetails += ", monthly Deposit: " + monthlyDeposit->getString(2);
	}
	accountDetails += " , Annual Interest Rate: " + annualInterestRate->getString(2) + "%";
	 
	return accountDetails;
}
DoubleWrapper* InvestmentAccount::getInitialAmount()
{
	return initialAmount;
}

DoubleWrapper* InvestmentAccount::getMonthlyDeposit()
{
	return monthlyDeposit;
}

DoubleWrapper* InvestmentAccount::getAnnualInterestRate()
{
	return annualInterestRate;
}




	