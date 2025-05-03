#include "Point.hpp"
#include "Fixed.hpp"

Point::Point()
{
}

Point::Point(float x, float y): x(x), y(y)
{
}

Point::Point(const Point& copy): x(copy.x), y(copy.y)
{

}
Point& Point::operator=(const Point& point)
{
    if (this == &point)
        return (*this);
    return (*this);
}

const Fixed Point::get_x() const
{
    return x;
}

const Fixed Point::get_y() const
{
    return y;
}

Point::~Point()
{
}