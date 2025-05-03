#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point();
		Point(float x, float y);
		Point(const Point& copy);
		Point& operator=(const Point& copy);

		const Fixed get_x() const;
		const Fixed get_y() const;
		~Point();
};

#endif