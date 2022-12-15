#pragma once
#include "IParsable.h"

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