#pragma once
#include "Object.h"
#include <string>
#include <vector>

using namespace std;

#include "Utils.h"
#include "IShape.h"

class IParsable : public Object
{
public:
    virtual Object* parse(string) = 0;
};

class RectangleParser : public IParsable
{
public:
    RectangleParser() { }

public:
    Object* parse(string data)
    {
        Object* result = NULL;

        vector <string> tokens = Utils::String::split(data, ", ");
        vector <string> width = Utils::String::split(tokens[0], "=");
        vector <string> height = Utils::String::split(tokens[1], "=");

        double w = stod(width[1]);
        double h = stod(height[1]);

        try
        {
            result = new Rectangle(w, h);
        }
        catch (exception ex)
        {
            result = NULL; // Eat exception
        }

        return result;
    }

public:
    string toString()
    {
        return "RectangleParser";
    }
};

class SquareParser : public IParsable
{
public:
    SquareParser() { }

public:
    Object* parse(string data)
    {
        Object* result = NULL;

        vector <string> tokens = Utils::String::split(data, "=");

        double a = stod(tokens[1]);

        try
        {
            result = new Square(a);
        }
        catch (exception ex)
        {
            result = NULL; // Eat exception
        }

        return result;
    }

public:
    string toString()
    {
        return "SquareParser";
    }
};

class CircleParser : public IParsable
{
public:
    CircleParser() { }

public:
    Object* parse(string data)
    {
        Object* result = NULL;

        vector <string> tokens = Utils::String::split(data, "=");

        double radius = stod(tokens[1]);

        try
        {
            result = new Circle(radius);
        }
        catch (exception ex)
        {
            result = NULL; // Eat exception
        }

        return result;
    }

public:
    string toString()
    {
        return "CircleParser";
    }
};