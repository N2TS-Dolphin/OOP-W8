#pragma once
#include "Object.h"

using namespace std;

class Integer : public Object
{
private:
	int _value;

public:
	Integer(int);
	int value();
};