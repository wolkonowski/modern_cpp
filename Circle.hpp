#pragma once

#include "Shape.hpp"
#include <math.h>

class Circle final: public Shape
{
    using Shape::Shape;
public:
    Circle(double r);
    Circle(const Circle & other) = default;
    Circle(Circle &&) noexcept = default;
    Circle& operator=(Circle&&) noexcept = default;
    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getRadius() const;
    void print() const override;
    [[deprecated]]
    constexpr double getPI() {
        return M_PI;
    }

private:

    double r_;
};
