/*
Wasan Alabed
Cs210 project 2
july 31, 2022
*/

#include <iostream>
#include <iomanip>
#include "Account.h"
#include "InvestmentAccount.h"
#include<string>

using namespace std;

const double TOLERANCE = 0.01;

//Main Class function prototypes
void displayOutput(Account* account, int numberOfYears) {    //Displays the account details, as well as account balances and interest earned for each year.
    cout << "ACCOUNT DETAILS" << endl;
    cout << "Name: " << account->getName() << endl;
    cout << "Address: " << account->getAddress() << endl;
    cout << "Account Number: " << account->getAccountNumber() << endl;
    cout << "Account Type: " << account->getAccountType() << endl;
    cout << "Account Details: " << account->getAccountDetails() << endl;
    cout << string(66, '=') << endl;
    cout << setw(9) << "Year" << setw(28) << "Year End Balance " << setw(30) << "Year End Earened Interest" << endl;
    cout << string(66, '-') << endl;
    
    for (int year = 1; year <= numberOfYears; year++) {
        cout << fixed << showpoint<<setprecision(2);
        cout << setw(7)<< year << setw(24) << account->getEndingBalance(year) << setw(25) <<
            account->getInterestEarned(year) << endl;
    }
    cout << string(66, '-') << endl;
}

int main()

{
    //Get the input
    string name;
    string address;
    int accountNumber;
    string initialAmountInput;
    string monthlyDepositInput;
    string annualInterestRateInput;
    int numberOfYears;
   
    cout << "Data Input" << endl;
    cout<<endl;
    cout << "Enter Name" << endl;
    getline(cin, name);

    cout << "Address: " << endl;
    getline(cin, address);

    cout << "Account Number" << endl;
    cin >> accountNumber;

    DoubleWrapper* initialAmount = 0;
    DoubleWrapper* monthlyDeposit = 0;
    DoubleWrapper* annualInterestRate = 0;
    bool exceptionThroan = false;

    do {
        try {
            cout << "Initial Investment Amount: " << endl;
            cin >> initialAmountInput;
            initialAmount = new DoubleWrapper(initialAmountInput);

            cout << "Monthly Deposit: " << endl;
            cin >> monthlyDepositInput;
            monthlyDeposit = new DoubleWrapper(monthlyDepositInput);

            cout << "Annual Interest Rate: " << endl;
            cin >> annualInterestRateInput;
            annualInterestRate = new DoubleWrapper(annualInterestRateInput);

            cout << "Number of years:" << endl;
            cin >> numberOfYears;
            cout << string(66, '-') << endl;
        }
        catch (...) {
            cout << "Invalid format for input.Re-enter values" << endl;
            exceptionThroan = true;
        }

    } while (exceptionThroan);

    // InvestmentAccount pointer variables... with  monthly deposit
   
    InvestmentAccount* account1 = new InvestmentAccount(name, address, accountNumber, initialAmount,
        annualInterestRate, monthlyDeposit);
        account1->getAccountDetails();
        
    // InvestmentAccount pointer variables... without monthly deposit
    InvestmentAccount* account2 = new InvestmentAccount(name, address, accountNumber, initialAmount,
        annualInterestRate);
        account2->getAccountDetails();
             
       //Display the output for account 1
        displayOutput(account1, numberOfYears);

        //Display the output for account 1
        displayOutput(account2, numberOfYears);
    }



            


