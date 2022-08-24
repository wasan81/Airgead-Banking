#include "pch.h"
#include "../Project 2/Account.h"
#include "../Project 2/Account.cpp"
#include "../Project 2/InvestmentAccount.h"
#include "../Project 2/InvestmentAccount.cpp"

#include "../Project 2/DoubleWrapper.h"
#include "../Project 2/DoubleWrapper.cpp"

//TO RUN THE TESTS
//Right-click Project 1 Test in solution explorer.
//Set as startup project
//Run as normal project


TEST(DoubleWrapper, DoubleWrapper) {

	DoubleWrapper dw = DoubleWrapper("2.34537");
	EXPECT_EQ(dw.getString(1), "2.3");
	EXPECT_EQ(dw.getString(2), "2.35");
	EXPECT_EQ(dw.getString(3), "2.345");
	EXPECT_EQ(dw.getString(4), "2.3454");
	EXPECT_EQ(dw.getString(5), "2.34537");


	dw = DoubleWrapper("2.9945");
	EXPECT_EQ(dw.getString(1), "3.0");
	EXPECT_EQ(dw.getString(2), "2.99");
	EXPECT_EQ(dw.getString(3), "2.995");
	EXPECT_EQ(dw.getString(4), "2.9945");

	EXPECT_EQ(dw.getString(5), "2.99450");
}


const double TOLERANCE = 0.01;

void validateBalance(Account* account, int numberOfYears, double expectedBalance) {
	double endingBalance = account->getEndingBalance(numberOfYears);
	double difference = endingBalance - expectedBalance;
	EXPECT_TRUE(fabs(difference) < TOLERANCE);
}

void validateInterestEarned(Account* account, int numberOfYears, double expectedInterest) {
	double interestEarned = account->getInterestEarned(numberOfYears);
	double difference = interestEarned - expectedInterest;
	EXPECT_TRUE(fabs(difference) < TOLERANCE);
}


const double account1InitialAmount = 1;
const double account1AnnualInterestRate = 5;
const double account1MonthlyDeposit = 50;
DoubleWrapper* ptrAccount1InitialAmount = new DoubleWrapper("1.0");
DoubleWrapper* ptrAccount1AnnualInterestRate = new DoubleWrapper("5.0");
DoubleWrapper* ptrAccount1MonthlyDeposit = new DoubleWrapper("50.0");
const string name = "Joe Jones";
const string address = "123 Main St";
const long accountNumber = 123456789;

TEST(TestAccountDetails, WithMonthlyDeposit) {
	InvestmentAccount* account = new InvestmentAccount(name, address, accountNumber, ptrAccount1InitialAmount, ptrAccount1AnnualInterestRate, ptrAccount1MonthlyDeposit);

	EXPECT_EQ(account->getName(), name);
	EXPECT_EQ(account->getAddress(), address);
	EXPECT_EQ(account->getAccountNumber(), accountNumber);
	EXPECT_TRUE(fabs(account->getAnnualInterestRate()->getValue() - account1AnnualInterestRate) < TOLERANCE);
	EXPECT_TRUE(fabs(account->getInitialAmount()->getValue() - account1InitialAmount) < TOLERANCE);
	EXPECT_TRUE(fabs(account->getMonthlyDeposit()->getValue() - account1MonthlyDeposit) < TOLERANCE);
	EXPECT_EQ(account->getAccountType(), "Investment-Compound Monthly, With Monthly Deposit");
}

TEST(TestAccountDetails, WithoutMonthlyDeposit) {
	InvestmentAccount* account = new InvestmentAccount(name, address, accountNumber, ptrAccount1InitialAmount, ptrAccount1AnnualInterestRate );

	EXPECT_EQ(account->getName(), name);
	EXPECT_EQ(account->getAddress(), address);
	EXPECT_EQ(account->getAccountNumber(), accountNumber);
	EXPECT_TRUE(fabs(account->getAnnualInterestRate()->getValue() - account1AnnualInterestRate) < TOLERANCE);
	EXPECT_TRUE(fabs(account->getInitialAmount()->getValue() - account1InitialAmount) < TOLERANCE);
	EXPECT_TRUE(account->getMonthlyDeposit()->getValue() < TOLERANCE);
	EXPECT_EQ(account->getAccountType(), "Investment-Compound Monthly, Without Monthly Deposit");
}


TEST(TestAccountBalances, WithMonthlyDeposit) {
	
	double expectedBalances[] = { 617.55, 1265.65, 1946.90, 2663.01, 3415.76 };

	InvestmentAccount* account = new InvestmentAccount(name, address, accountNumber, ptrAccount1InitialAmount, ptrAccount1AnnualInterestRate, ptrAccount1MonthlyDeposit);
	int year;
	int numberOfYears = sizeof(expectedBalances) / sizeof(expectedBalances[0]);

	for (year = 1; year <= numberOfYears; year++) {
		validateBalance(account, year, expectedBalances[year - 1]);
	}
}


TEST(TestAccountBalances, WithoutMonthlyDeposit) {

	double expectedBalances[] = { 1.05, 1.10, 1.16, 1.22, 1.28 };

	InvestmentAccount* account = new InvestmentAccount(name, address, accountNumber, ptrAccount1InitialAmount, ptrAccount1AnnualInterestRate);

	int year;
	int numberOfYears = sizeof(expectedBalances) / sizeof(expectedBalances[0]);

	for (year = 1; year <= numberOfYears; year++) {
		validateBalance(account, year, expectedBalances[year - 1]);
	}
}

TEST(TestAccountInterest, WithMonthlyDeposit) {
	
	double expectedInterest[] = { 16.55, 48.10, 81.25, 116.11, 152.75 };

	InvestmentAccount* account = new InvestmentAccount(name, address, accountNumber, ptrAccount1InitialAmount, ptrAccount1AnnualInterestRate, ptrAccount1MonthlyDeposit);

	int year;
	int numberOfYears = sizeof(expectedInterest) / sizeof(expectedInterest[0]);

	for (year = 1; year <= numberOfYears; year++) {
		validateInterestEarned(account, year, expectedInterest[year - 1]);
	}
}


TEST(TestAccountInterest, WithoutMonthlyDeposit) {
	
	double expectedInterest[] = { 0.05, 0.05, 0.06, 0.06, 0.06 };

	InvestmentAccount* account = new InvestmentAccount(name, address, accountNumber, ptrAccount1InitialAmount, ptrAccount1AnnualInterestRate);

	int year;
	int numberOfYears = sizeof(expectedInterest) / sizeof(expectedInterest[0]);

	for (year = 1; year <= numberOfYears; year++) {
		validateInterestEarned(account, year, expectedInterest[year - 1]);
	}
}


const double account2InitialAmount = 1000;
const double account2AnnualInterestRate = 4.25;
const double account2MonthlyDeposit = 200;
DoubleWrapper* ptrAccount2InitialAmount = new DoubleWrapper("1000.0");
DoubleWrapper* ptrAccount2AnnualInterestRate = new DoubleWrapper("4.25");
DoubleWrapper* ptrAccount2MonthlyDeposit = new DoubleWrapper("200.0");

TEST(TestAccount2Details, WithMonthlyDeposit) {

	InvestmentAccount* account = new InvestmentAccount(name, address, accountNumber, ptrAccount2InitialAmount, ptrAccount2AnnualInterestRate, ptrAccount2MonthlyDeposit);

	EXPECT_TRUE(fabs(account->getAnnualInterestRate()->getValue() - account2AnnualInterestRate) < TOLERANCE);
	EXPECT_TRUE(fabs(account->getInitialAmount()->getValue() - account2InitialAmount) < TOLERANCE);
	EXPECT_TRUE(fabs(account->getMonthlyDeposit()->getValue() - account2MonthlyDeposit) < TOLERANCE);
}

TEST(TestAccount2Details, WithoutMonthlyDeposit) {

	InvestmentAccount* account = new InvestmentAccount(name, address, accountNumber, ptrAccount2InitialAmount, ptrAccount2AnnualInterestRate);

	EXPECT_TRUE(fabs(account->getAnnualInterestRate()->getValue() - account2AnnualInterestRate) < TOLERANCE);
	EXPECT_TRUE(fabs(account->getInitialAmount()->getValue() - account2InitialAmount) < TOLERANCE);
	EXPECT_TRUE(account->getMonthlyDeposit()->getValue() < TOLERANCE);
}


TEST(TestAccount2Balances, WithMonthlyDeposit) {

	double expectedBalances[] = { 3499.31, 6106.94, 8827.57, 11666.11, 14627.67, 17717.57, 20941.39, 24304.91 };

	InvestmentAccount* account = new InvestmentAccount(name, address, accountNumber, ptrAccount2InitialAmount, ptrAccount2AnnualInterestRate, ptrAccount2MonthlyDeposit);
	int year;
	int numberOfYears = sizeof(expectedBalances) / sizeof(expectedBalances[0]);

	for (year = 1; year <= numberOfYears; year++) {
		validateBalance(account, year, expectedBalances[year - 1]);
	}
}


TEST(TestAccount2Balances, WithoutMonthlyDeposit) {

	double expectedBalances[] = { 1043.34, 1088.55, 1135.73, 1184.95, 1236.30, 1289.88, 1345.78, 1404.10 };

	InvestmentAccount* account = new InvestmentAccount(name, address, accountNumber, ptrAccount2InitialAmount, ptrAccount2AnnualInterestRate);

	int year;
	int numberOfYears = sizeof(expectedBalances) / sizeof(expectedBalances[0]);

	for (year = 1; year <= numberOfYears; year++) {
		validateBalance(account, year, expectedBalances[year - 1]);
	}
}

TEST(TestAccount2Interest, WithMonthlyDeposit) {

	double expectedInterest[] = { 99.31, 207.63, 320.63, 438.54, 561.56, 689.90,823.81, 963.53 };

	InvestmentAccount* account = new InvestmentAccount(name, address, accountNumber, ptrAccount2InitialAmount, ptrAccount2AnnualInterestRate, ptrAccount2MonthlyDeposit);

	int year;
	int numberOfYears = sizeof(expectedInterest) / sizeof(expectedInterest[0]);

	for (year = 1; year <= numberOfYears; year++) {
		validateInterestEarned(account, year, expectedInterest[year - 1]);
	}
}


TEST(TestAccount2Interest, WithoutMonthlyDeposit) {

	double expectedInterest[] = { 43.34, 45.22, 47.18, 49.22, 51.35, 53.58, 55.90, 58.32 };

	InvestmentAccount* account = new InvestmentAccount(name, address, accountNumber, ptrAccount2InitialAmount, ptrAccount2AnnualInterestRate);

	int year;
	int numberOfYears = sizeof(expectedInterest) / sizeof(expectedInterest[0]);

	for (year = 1; year <= numberOfYears; year++) {
		validateInterestEarned(account, year, expectedInterest[year - 1]);
	}
}