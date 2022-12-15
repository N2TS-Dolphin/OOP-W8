#pragma once
#include "IParsable.h"
#include "Employee.h"

class Manager : public Employee
{
private:
	int _employeeCount;
	int _paymentPerEmployee;
	int _baseSalary;

public:
	Manager(int employeeCount, int paymentPerEmployee, int baseSalary)
	{
		_employeeCount = employeeCount;
		_paymentPerEmployee = paymentPerEmployee;
		_baseSalary = baseSalary;
	}

public:
	int salary()
	{
		return _employeeCount * _paymentPerEmployee + _baseSalary;
	}

	string toString() { return "Manager"; }
};