#pragma once
#include "IParsable.h"

class AddPrefix : public Object
{
private:
	string _AddPrefix;

public:
	AddPrefix()
	{
		_AddPrefix = "CV";
	}

public:
	string toString() { return "RemoveSpecialChars"; }
};