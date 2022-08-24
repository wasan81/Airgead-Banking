#pragma once

#include <string>
using namespace std;

class DoubleWrapper
{
public:
	DoubleWrapper(string value);

	string getString();
	string getString(int places);
	double getValue();


private:
	int integerPart;
	int decimalPart;
	string value;
	bool checkIfPowerOf10(int value);

};

