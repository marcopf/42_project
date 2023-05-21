#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
public:
	Fixed	x;
	Fixed	y;
	void	operator=(Point& cpy);
	Point(Fixed x, Fixed y);
	Point(Point& cpy);
	Point(void);
	~Point();
};

#endif
