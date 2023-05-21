#include "Point.hpp"

Point::Point(Fixed x, Fixed y)
{
	this->x = x;
	this->y = y;
}

Point::Point(void)
{
	x = 0;
	y = 0;
}

Point::Point(Point& cpy)
{
	x = cpy.x;
	y = cpy.y;
}

Point::~Point()
{
}

void	Point::operator=(Point& cpy)
{
	this->x = x;
	this->y = y;
}
