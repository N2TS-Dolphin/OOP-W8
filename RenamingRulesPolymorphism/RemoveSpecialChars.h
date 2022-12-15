#pragma once
#include "IParsable.h"

class RemoveSpecialChars : public Object
{
private:
	vector <string> _SpecialChars;

public:
	RemoveSpecialChars(vector<string>SpecialChars)
	{
		_SpecialChars = SpecialChars;
	}

public:
	string toString() { return "RemoveSpecialChars"; }
};