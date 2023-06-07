#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string.h>

class Fixed
{
private:
	int					val;
	const static int	lit = 8;
public:
	int		getRawBits(void);
	void	setRawBits(const int raw);
	void	operator=(Fixed& copy);
	Fixed(Fixed &copy);
	Fixed(int val);
	Fixed(/* args */);
	~Fixed();
};

#endif