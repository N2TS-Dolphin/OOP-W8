#pragma once
#include "Object.h"
#include "Utils.h"
#include "IRule.h"

#include "RemoveSpecialChars.h"
#include "OneSpaceOnly.h"
#include "AddCurrentMonth.h"
#include "AddPrefix.h"
#include "Replace.h"

#include <vector>
#include <string>
#include <sstream>

class IParsable : public Object
{
private:
	string key;

public:
	virtual Object* parse(string) = 0;
	virtual string parsedObjectName() = 0;

public:
	string toString() { return "IParsable"; }
};

class RemoveSpecialCharsParser : public IParsable
{
public:
	RemoveSpecialCharsParser() {}

public:
	Object* parse(string data)
	{
		Object* result = NULL;

		vector <string> temp = Utils::String::split(data, "=");
		vector <string> tokens;

		for (int i = 0; i < temp[1].length(); i++)
			tokens.push_back(temp[1].substr(i, 1));

		try
		{
			result = new RemoveSpecialChars(tokens);
		}
		catch (exception ex)
		{
			result = NULL; // Eat exception
		}

		return result;
	}

	string parsedObjectName() { return "RemoveSpecialChars"; }

	string toString() { return "RemoveSpecialCharsParser"; }
};

class OneSpaceOnlyParser : public IParsable
{
public:
	OneSpaceOnlyParser() {}

public:
	Object* parse(string data)
	{
		Object* result = NULL;

		try
		{
			result = new OneSpaceOnly();
		}
		catch (exception ex)
		{
			result = NULL; // Eat exception
		}

		return result;
	}

	string parsedObjectName() { return "OneSpaceOnly"; }

	string toString() { return "OneSpaceOnlyParser"; }
};

class AddCurrentMonthParser : public IParsable
{
public:
	AddCurrentMonthParser() {}

public:
	Object* parse(string data)
	{
		Object* result = NULL;

		try
		{
			result = new AddCurrentMonth();
		}
		catch (exception ex)
		{
			result = NULL; // Eat exception
		}

		return result;
	}

	string parsedObjectName() { return "AddCurrentMonth"; }

	string toString() { return "AddCurrentMonthParser"; }
};

class AddPrefixParser : public IParsable
{
public:
	AddPrefixParser() {}

public:
	Object* parse(string data)
	{
		Object* result = NULL;

		try
		{
			result = new AddPrefix();
		}
		catch (exception ex)
		{
			result = NULL; // Eat exception
		}

		return result;
	}

	string parsedObjectName() { return "AddPrefix"; }

	string toString() { return "AddPrefixParser"; }
};

class ReplaceParser : public IParsable
{
public:
	ReplaceParser() {}

public:
	Object* parse(string data)
	{
		Object* result = NULL;

		try
		{
			result = new Replace();
		}
		catch (exception ex)
		{
			result = NULL; // Eat exception
		}

		return result;
	}

	string parsedObjectName() { return "Replace"; }

	string toString() { return "ReplaceParser"; }
};