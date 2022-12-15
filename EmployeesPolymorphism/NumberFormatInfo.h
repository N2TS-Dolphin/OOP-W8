#pragma once
#include "Object.h"

class NumberFormatInfo : public Object 
{
private:
	string _currencyDecimalSeparator = ".";
	string _currencySymbol = "d";
	int _currencyPositive = 3;
	string _currencyPositiveFormat = "n $";

public:
	string currencyDecimalSeparator();
	string currencySymbol();
	int currencyPositive();
	string currencyPositiveFormat();

public:
	string toString() { return "NumberFormatInfo"; }
};