#pragma once
#include "IParsable.h"
#include "IRule.h"

#include <sstream>

class OneSpaceOnly : public IRule
{
public:
	OneSpaceOnly() { }

public:
	string rename(string data)
	{
		int a = 0;
		stringstream builder;
		while (a < data.length())
		{
			if (data[a] != 32)
			{
				stringstream temp;
				for (int i = a; i < data.length(); i++)
				{
					if (data[i] == 32)
						break;
					else
					{
						temp << data[i];
						a++;
					}
				}

				if (a == data.length())
					builder << temp.str();
				else
					builder << temp.str() << " ";
			}
			else
				a++;
		}

		return builder.str();
	}

	string toString() { return "OneSpaceOnly"; }
};