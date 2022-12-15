#pragma once
#include "IParsable.h"
#include "IRule.h"

#include <sstream>

class AddPrefix : public IRule
{
private:
	string _AddPrefix;

public:
	AddPrefix()
	{
		_AddPrefix = "CV";
	}

public:
	string rename(string data)
	{
		stringstream builder;

		builder << _AddPrefix << " " << data;

		string result = builder.str();
		return result;
	}
	
	string toString() { return "RemoveSpecialChars"; }
};