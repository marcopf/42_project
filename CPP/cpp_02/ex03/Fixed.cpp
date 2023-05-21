#include "Fixed.hpp"

Fixed::Fixed(Fixed &copy)
{
	this->val = copy.getRawBits();
}

Fixed::Fixed(const Fixed &copy)
{
	this->val = copy.getRawBits();
}

Fixed::Fixed(void)
{
	this->val = 0;
}

Fixed::Fixed(const int value)
{
	int	fix;

	fix = value * 256;
	this->val = fix;
}

Fixed::Fixed(const float value)
{
	int	fix;

	fix = roundf(value * pow(2, this->lit));
	this->val = fix;
}

Fixed::~Fixed()
{
}

void Fixed::operator=(Fixed& copy)
{
	this->val = copy.getRawBits();
}

void Fixed::operator=(const Fixed& copy)
{
	this->val = copy.getRawBits();
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
	os << fix.toFloat();
	return (os);
}

int	Fixed::getRawBits(void)const
{
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

//operazioni

Fixed	Fixed::operator+(const Fixed& toAdd)
{
	Fixed	toRet;

	toRet.setRawBits(roundf((toAdd.toFloat() + this->toFloat()) * (pow(2, this->lit))));
	return (toRet);
}

Fixed	Fixed::operator-(const Fixed& toAdd)
{
	Fixed	toRet;

	toRet.setRawBits(roundf((toAdd.toFloat() - this->toFloat()) * (pow(2, this->lit))));
	return (toRet);
}

Fixed	Fixed::operator/(const Fixed& toAdd)
{
	Fixed	toRet;

	toRet.setRawBits(roundf((toAdd.toFloat() / this->toFloat()) * (pow(2, this->lit))));
	return (toRet);
}

Fixed	Fixed::operator*(const Fixed& toAdd)
{
	Fixed	toRet;

	toRet.setRawBits(roundf((toAdd.toFloat() * this->toFloat()) * (pow(2, this->lit))));
	return (toRet);
}

//comparazioni

bool	Fixed::operator>(const Fixed& comp)
{
	if (this->getRawBits() > comp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& comp)
{
	if (this->getRawBits() < comp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& comp)
{
	if (this->getRawBits() >= comp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& comp)
{
	if (this->getRawBits() <= comp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& comp)
{
	if (this->getRawBits() == comp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& comp)
{
	if (this->getRawBits() != comp.getRawBits())
		return (true);
	return (false);
}

//post/pre fix operator

Fixed& Fixed::operator++(void)
{
	++this->val;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	--this->val;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->val++;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->val--;
	return (temp);
}

//max min func

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a < b)
		return (b);
	return (a);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if ((Fixed)a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if ((Fixed)a < b)
		return (b);
	return (a);
}