#include "Fixed.hpp"

Fixed::Fixed(Fixed &copy)
{
	std::cout << "copy constructor called\n";
	this->val = copy.getRawBits();
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "copy constructor called\n";
	this->val = copy.getRawBits();
}

Fixed::Fixed(void)
{
	std::cout << "default constructor called\n";
	this->val = 0;
}

Fixed::Fixed(const int value)
{
	int	fix;

	std::cout << "int constructor called\n";
	fix = value * 256;
	this->val = fix;
}

Fixed::Fixed(const float value)
{
	int	fix;

	std::cout << "float constructor called\n";
	fix = roundf(value * pow(2, this->lit));
	this->val = fix;
}

Fixed::~Fixed()
{
	std::cout << "deconstructor called\n";
}

void Fixed::operator=(Fixed& copy)
{
	std::cout << "copy assignment constructor called\n";
	this->val = copy.getRawBits();
}

void Fixed::operator=(const Fixed& copy)
{
	std::cout << "copy assignment constructor called\n";
	this->val = copy.getRawBits();
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
	os << fix.toFloat();
	return (os);
}

int	Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called\n";
	return (val);
}

void	Fixed::setRawBits(int val)
{
	this->val = val;
}

int	Fixed::toInt(void)const
{
	return (round(this->val / pow(2, this->lit)));
}

float	Fixed::toFloat(void)const
{
	return ((float)this->val / (float)pow(2, this->lit));
}