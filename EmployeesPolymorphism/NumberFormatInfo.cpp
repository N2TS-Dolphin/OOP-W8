#include "NumberFormatInfo.h"
#include <sstream>

string NumberFormatInfo::currencyDecimalSeparator()
{
	return _currencyDecimalSeparator;
}

int NumberFormatInfo::currencyPositive()
{
	return _currencyPositive;
}

string NumberFormatInfo::currencyPositiveFormat()
{
	return _currencyPositiveFormat;
}

string NumberFormatInfo::currencySymbol()
{
	return _currencySymbol;
}