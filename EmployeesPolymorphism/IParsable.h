#pragma once
#include "Object.h"
#include "Utils.h"

#include "DailyEmployee.h"
#include "ProductEmployee.h"
#include "Manager.h"

#include <vector>
#include <string>

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

class DailyEmployeeParser : public IParsable
{
public:
	DailyEmployeeParser()
	{
		//Do nothing 
	}

public:
	Object* parse(string data)
	{
		Object* result = NULL;

		vector <string> tokens = Utils::String::split(data, ", ");
		vector <string> dayCount = Utils::String::split(tokens[0], "=");
		vector <string> paymentPerDay = Utils::String::split(tokens[1], "=");

		int dC = stoi(dayCount[1]);
		int pPD = stoi(paymentPerDay[1]);

		try
		{
			result = new DailyEmployee(dC, pPD);
		}
		catch (exception ex)
		{
			result = NULL; // Eat exception
		}

		return result;
	}

	string parsedObjectName() { return "DailyEmployee"; }

	string toString() { return "DailyEmployeeParser"; }
};

class ProductEmployeeParser : public IParsable
{
public:
	ProductEmployeeParser()
	{
		//Do nothing 
	}

public:
	Object* parse(string data)
	{
		Object* result = NULL;

		vector <string> tokens = Utils::String::split(data, ", ");
		vector <string> productCount = Utils::String::split(tokens[0], "=");
		vector <string> paymentPerProduct = Utils::String::split(tokens[1], "=");

		int pC = stoi(productCount[1]);
		int pPP = stoi(paymentPerProduct[1]);

		try
		{
			result = new ProductEmployee(pC, pPP);
		}
		catch (exception ex)
		{
			result = NULL; // Eat exception
		}

		return result;
	}
	string parsedObjectName() { return "ProductEmployee"; }

	string toString() { return "ProductEmployeeParser"; }
};

class ManagerParser : public IParsable
{
public:
	ManagerParser()
	{
		//Do nothing 
	}

public:
	Object* parse(string data)
	{
		Object* result = NULL;

		vector <string> tokens = Utils::String::split(data, ", ");
		vector <string> employeeCount = Utils::String::split(tokens[0], "=");
		vector <string> paymentPerEmployee = Utils::String::split(tokens[1], "=");
		vector <string> baseSalary = Utils::String::split(tokens[2], "=");

		int eC = stoi(employeeCount[1]);
		int pPE = stoi(paymentPerEmployee[1]);
		int bS = stoi(baseSalary[1]);

		try
		{
			result = new Manager(eC, pPE, bS);
		}
		catch (exception ex)
		{
			result = NULL; // Eat exception
		}

		return result;
	}
	string parsedObjectName() { return "Manager"; }

	string toString() { return "ManagerParser"; }
};