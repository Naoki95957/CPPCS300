#include <iostream>
#include "Point.h"

Point::Point(int x, int y)
{
    setX(x);
    setY(y);
}

void Point::setX(int x)
{
    Point::x = x;
}

void Point::setY(int y)
{
    Point::y = y;
}

Point Point::operator+(Point n)
{
    setX(n.getX() + getX());
    setY(n.getY() + getY());
    return *this;
}

const int Point::getX()
{
    return Point::x;
}

const int Point::getY()
{
    return Point::y;
}