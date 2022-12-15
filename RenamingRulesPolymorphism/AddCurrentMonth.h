#pragma once
#include "IParsable.h"
#include "IRule.h"

#include <sstream>

class AddCurrentMonth : public IRule
{
private:
	string _CurrentMonth;

public:
	AddCurrentMonth()
	{
		_CurrentMonth = "1122";
	}

public:
	string rename(string data)
	{
		stringstream builder;

		builder << _CurrentMonth << " " << data;

		string result = builder.str();
		return result;
	}

	string toString() { return "AddCurrentMonth"; }
};