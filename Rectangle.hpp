#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
    using Shape::Shape;
public:
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other) = default;

    virtual double getArea() const override;
    virtual double getPerimeter() const override;
    virtual double getX() const final;
    double getY() const;
    virtual void print() const override;

private:
    double x_;
    double y_;
};
