#pragma once
#include "IParsable.h"

class AddCurrentMonth : public Object
{
private:
	string _CurrentMonth;

public:
	AddCurrentMonth()
	{
		_CurrentMonth = "1122";
	}

public:
	string toString() { return "AddCurrentMonth"; }
};