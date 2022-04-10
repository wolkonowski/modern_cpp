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
    Shape(Shape &&) noexcept = default;
    Shape& operator=(Shape&&) noexcept = default;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

};
