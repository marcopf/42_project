#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
	int					val;
	const static int	lit = 8;
public:
	int				getRawBits(void)const;
	void			setRawBits(const int raw);
	void			operator=(Fixed& copy);
	void			operator=(const Fixed& copy);
	friend std::ostream&	operator<<(std::ostream& os, const Fixed& fix);
	int				toInt(void)const;
	float			toFloat(void)const;
	Fixed(Fixed &copy);
	Fixed(const Fixed &copy);
	Fixed(const int val);
	Fixed(const float val);
	Fixed(/* args */);
	~Fixed();
};

#endif