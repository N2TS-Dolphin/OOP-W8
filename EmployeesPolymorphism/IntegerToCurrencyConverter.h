#pragma once
#include "IValueConverter.h"
#include <sstream>

class IntegerToCurrencyConverter : public IValueConverter
{
public:
	string convert(int);
	string toString() { return "IntegerToCurrencyConverter"; }
};