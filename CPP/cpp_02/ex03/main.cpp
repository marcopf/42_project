#include "Point.hpp"

bool PointInTriangle (Point pt, Point v1, Point v2, Point v3);

int	main(void)
{
	std::cout << std::boolalpha

		<< "a(0, 0), b(0, 5), c(5, 0), point(1, 1): "
		<< PointInTriangle(Point(0, 0), Point(0, 5), Point(5, 0), Point(1, 1)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0, 5): "
		<< PointInTriangle(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 5)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0, 3): "
		<< PointInTriangle(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 3)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0, 0): "
		<< PointInTriangle(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 0)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0.1, 0.01): "
		<< PointInTriangle(Point(0, 0), Point(0, 5), Point(5, 0), Point(0.1f, 0.01f)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(10, 0.01): "
		<< PointInTriangle(Point(0, 0), Point(0, 5), Point(5, 0), Point(10, 0.01f)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0, -0.01): "
		<< PointInTriangle(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, -0.01f)) << std::endl;
}