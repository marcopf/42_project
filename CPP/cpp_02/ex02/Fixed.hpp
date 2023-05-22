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
	bool					operator>(const Fixed& comp)const;
	bool					operator<(const Fixed& comp)const;
	bool					operator>=(const Fixed& comp)const;
	bool					operator<=(const Fixed& comp)const;
	bool					operator==(const Fixed& comp)const;
	bool					operator!=(const Fixed& comp)const;
	Fixed					operator+(const Fixed& toAdd)const;
	Fixed					operator-(const Fixed& toAdd)const;
	Fixed					operator*(const Fixed& toAdd)const;
	Fixed					operator/(const Fixed& toAdd)const;
	Fixed&					operator++(void);
	Fixed&					operator--(void);
	Fixed					operator++(int);
	Fixed					operator--(int);
	static Fixed&			min(Fixed& a, Fixed& b);
	static const Fixed&		min(const Fixed& a, const Fixed& b);
	static Fixed&			max(Fixed& a, Fixed& b);
	static const Fixed&		max(const Fixed& a, const Fixed& b);
	int						getRawBits(void)const;
	void					setRawBits(const int raw);
	Fixed&					operator=(Fixed const &other);
	friend std::ostream&	operator<<(std::ostream& os, const Fixed& fix);
	int						toInt(void)const;
	float					toFloat(void)const;
	Fixed(const Fixed &copy);
	Fixed(int val);
	Fixed(float val);
	Fixed(void);
	~Fixed();
};

#endif