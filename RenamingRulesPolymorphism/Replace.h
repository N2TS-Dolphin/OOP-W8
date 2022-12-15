#pragma once
#include "IParsable.h"
#include "IRule.h"

#include <cstring>

class Replace : public IRule
{
private:
	string _Replace;

public:
	Replace()
	{
		_Replace = "devops.pdf";
	}

public:
	string rename(string data)
	{
		int position = data.find("773423.pdf");

		string temp = data.replace(position, 10, _Replace);

		return data;
	}

	string toString() { return "Replace"; }
};