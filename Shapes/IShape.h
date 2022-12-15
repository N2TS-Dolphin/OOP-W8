#pragma once
#include "Object.h"
#include <sstream>

using namespace std;

class IShape : public Object
{
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Rectangle : public IShape
{
private:
    double _w;
    double _h;

public:
    Rectangle(double w, double h)
    {
        _w = w;
        _h = h;
    }

public:
    double area() { return _w * _h; }
    double perimeter() { return (_w + _h) * 2; }

public:
    string toString()
    {
        stringstream builder;

        builder << "Rectangle w=" << _w << ", h=" << _h;

        return builder.str();
    }
};

class Square : public IShape
{
private:
    double _a;

public:
    Square(double a)
    {
        _a = a;
    }

public:
    double area() { return _a * _a; }
    double perimeter() { return _a * 4; }

public:
    string toString()
    {
        stringstream builder;

        builder << "Square a=" << _a;

        return builder.str();
    }
};

class Circle : public IShape
{
private:
    double _radius;
    double PI = 3.14;

public:
    Circle(double radius)
    {
        _radius = radius;
    }

public:
    double area() { return _radius * _radius * PI; }
    double perimeter() { return _radius * 2 * PI; }

public:
    string toString()
    {
        stringstream builder;

        builder << "Circle r=" << _radius;

        return builder.str();
    }
};