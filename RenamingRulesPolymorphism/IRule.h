#pragma once
#include "Object.h"
#include <string>

class IRule : public Object
{
public:
    virtual string rename(string) = 0;
};