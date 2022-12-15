#pragma once
#include "IParsable.h"
#include "Employee.h"

class ProductEmployee : public Employee
{
private:
	int _productCount;
	int _paymentPerProduct;

public:
	ProductEmployee(int productCount, int paymentPerProduct)
	{
		_productCount = productCount;
		_paymentPerProduct = paymentPerProduct;
	}

public:
	int salary()
	{
		return _productCount * _paymentPerProduct;
	}

	string toString() { return "Product Employee"; }
};