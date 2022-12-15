#pragma once
#include "IParsable.h"
#include "IRule.h"

#include <sstream>

class RemoveSpecialChars : public IRule
{
private:
	vector <string> _SpecialChars = { ".", ",", "/", "`", "~", "-", "_", "=", "+" };
	string _Replace = " ";

public:
	RemoveSpecialChars() {}

public:
	string rename(string data)
	{
		cout << _SpecialChars.size() << endl;
		for (int j = 0; j < _SpecialChars.size(); j++)
		{
			cout << _SpecialChars[j] << " ";
		}
		cout << endl;
		stringstream builder;

		for (int i = 0; i < data.length(); i++)
		{
			stringstream temp;
			bool check = true;
			
			temp << data[i];

			for (int j = 0; j < _SpecialChars.size(); j++)
			{
				if (temp.str() == _SpecialChars[j])
				{
					builder << _Replace;
					check = false;
					break;
				}
			}

			if (check == true)
				builder << data[i];
		}

		string result = builder.str();
		return result;
	}

	string toString() { return "RemoveSpecialChars"; }
};