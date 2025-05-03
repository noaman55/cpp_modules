#include "Fixed.hpp"
#include "Point.hpp"

float   triangle_surface(Point const a, Point const b, Point const c)
{
    Fixed   surface;

    surface = Fixed(0.50f) * ((b.get_x() - a.get_x()) * (c.get_y()- a.get_y())
				- (b.get_y() - a.get_y()) *(c.get_x() - a.get_x()));

    if (surface.toFloat() >= 0)
        return surface.toFloat();
    return -surface.toFloat();
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	T[4];

	T[0] = triangle_surface(a, b, c);
	T[1] = triangle_surface(a, b, point);
	T[2] = triangle_surface(a, c, point);
	T[3] = triangle_surface(b, c, point);

	if (!T[0] || !T[1] || !T[2] || !T[3])
		return false;

	if (T[0] == T[1] + T[2] + T[3])
		return true;
	return false;
}