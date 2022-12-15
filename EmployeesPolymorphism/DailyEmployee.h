#pragma once
#include "IParsable.h"
#include "Employee.h"

class DailyEmployee : public Employee
{
private:
	int _dayCount;
	int _paymentPerDay;

public:
	DailyEmployee(int dayCount, int paymentPerDay)
	{
		_dayCount = dayCount;
		_paymentPerDay = paymentPerDay;
	}

public:
	int salary()
	{
		return _dayCount * _paymentPerDay;
	}

	string toString() { return "Daily Employee"; }
};