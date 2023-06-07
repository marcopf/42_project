#include "Fixed.hpp"

Fixed::Fixed(Fixed &copy)
{
	std::cout << "copy constructor called\n";
	this->val = copy.getRawBits();
}

Fixed::Fixed(void)
{
	std::cout << "default constructor called\n";
	this->val = 0;
}

Fixed::Fixed(int value)
{
	std::cout << "default constructor called\n";
	this->val = value;
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

int	Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called\n";
	return (val);
}

void	Fixed::setRawBits(int val)
{
	this->val = val;
}