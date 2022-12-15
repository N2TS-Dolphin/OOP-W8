#pragma once
#include "IParsable.h"

class RemoveSpecialChars : public IRule
{
private:
	vector <string> _SpecialChars;
	string _Replace = " ";

public:
	RemoveSpecialChars(vector<string>SpecialChars)
	{
		_SpecialChars = SpecialChars;
	}

public:
	string rename(string data)
	{
		stringstream builder;

		for (int i = 0; i < data.length(); i++)
		{
			stringstream temp;

			for (int j = 0; j < _SpecialChars.size(); j++)
			{
				temp << data[i];

				if (temp.str() == _SpecialChars[j])
					builder << _Replace;
				else
					builder << data[i];
			}
		}

		string result = builder.str();
		return result;
	}

	string toString() { return "RemoveSpecialChars"; }
};