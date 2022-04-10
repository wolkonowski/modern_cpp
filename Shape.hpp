#pragma once
#include "Color.hpp"
class Shape
{
private:
    Color color;
public:
    virtual ~Shape() {}
    Shape(Color c) : color(c) {}
    Shape() {}
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

};
