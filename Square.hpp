#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
    using Rectangle::Rectangle;
public:
    Square(double x);
    Square(const Square & other) = default;
    Square(Square &&) noexcept = default;
    Square& operator=(Square&&) noexcept = default;
    Square(Color c) : Rectangle(c){

    }
    double getArea() const override;
    double getPerimeter() const override;
    void print() const override;

private:
};
