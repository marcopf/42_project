#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

template <typename T>
void swap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}
template <typename T>
T	max(T &t1, T &t2)
{
	if (t1 > t2)
		return (t1);
	return (t2);
}
template <typename T>
T	min(T &t1, T &t2)
{
	if (t1 < t2)
		return (t1);
	return (t2);
}

#include <iostream>

#endif