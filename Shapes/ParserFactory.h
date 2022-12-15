#pragma once
#include "Object.h"
#include "IParsable.h"
#include <string>

using namespace std;

class ParserFactory : public Object
{
public:
    IParsable* create(string type)
    {
        IParsable* parser = NULL;

        if ("Rectangle" == type)
        {
            parser = new RectangleParser();
        }
        else if ("Square" == type)
        {
            parser = new SquareParser();
        }
        else if ("Circle" == type)
        {
            parser = new CircleParser();
        }

        return parser;
    }

public:
    string toString()
    {
        return "ParserFactory";
    }
};