#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
int	easyFind(T container, int n)
{
	std::vector<int>::iterator it;
	it = find(container.begin(), container.end(), n);
	if (it != container.end())
		return (1);
	return (0);
}

#endif