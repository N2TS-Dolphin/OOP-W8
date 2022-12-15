#pragma once
#include "IParsable.h"

class Replace : public Object
{
private:
	string _Replace;

public:
	Replace(string Replace)
	{
		_Replace = "devops";
	}

public:
	string toString() { return "Replace"; }
};