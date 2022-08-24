#include "DoubleWrapper.h"
#include <sstream>
#include <vector>


/*
Constructor
@param value - the value as a string (e.g. 3.14)
@throws invalid_argument exception if value is not in the form d.dddd
*/
DoubleWrapper::DoubleWrapper(string value) {

	this->value = value;

	string item;
	vector<string> result;
	stringstream ss(value);

	while (getline(ss, item, '.')) {
		result.push_back(item);
	}

	if (result.size() == 0 || result.size() > 2) {
		throw invalid_argument("Received invalid value: " + value);
	}
	else {
		this->integerPart = stoi(result[0]);

		if (result.size() == 2) {
			this->decimalPart = stoi(result[1]);
		}
		else {
			this->decimalPart = 0;
		}
	}
}

/*
Get the string represenation
@returns - the string representation
*/
string DoubleWrapper::getString() {
	return value;
}

/*
Get the string representation in rounded form.
@returns - the string representation
*/
string DoubleWrapper::getString(int places) {

	int intPart = integerPart;

	string strDecPart;
	int index;
	for (index = 0; index < places; index++) {
		if (index < to_string(decimalPart).size()) {
			strDecPart += to_string(decimalPart).at(index);
		}
		else {
			strDecPart += "0";
		}
		
	}

	int intDecPart = stoi(strDecPart);


	if (places < to_string(decimalPart).size()) {
		char digit = to_string(decimalPart).at(places);
		string roundDecider = string(1, digit);
		int intRoundDecider = stoi(roundDecider);

		if (intRoundDecider >= 5) {
			intDecPart++;
		}
	}


	if (checkIfPowerOf10(intDecPart)) {
		intPart++;
		strDecPart = "";
		
		for (index = 0; index < places; index++) {
			strDecPart += "0";
		}
	}
	else if (decimalPart != 0) {
		strDecPart = to_string(intDecPart);
	}

	return to_string(intPart) + "." + strDecPart;
}

/*
Get the value as a double. Do not use for output purposes.
@returns - the value as a double.
*/
double DoubleWrapper::getValue() {
	return integerPart + decimalPart / 100.0;
}

/*
Check if a value is a power of 10.
@param value - the value to check
@returns - indicator whether the value is a power of 10
*/
bool DoubleWrapper::checkIfPowerOf10(int value)
{
	if (value >= 10) {
		checkIfPowerOf10(value / 10);
	}
	else if (value == 1) {
		return true;
	}
	else {
		return false;
	}
}
