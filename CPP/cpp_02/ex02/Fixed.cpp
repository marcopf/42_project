#include "Fixed.hpp"

int		power(int val, int exp)
{
	int		i = -1;
	int		res = 1;
	while (++i < exp)
		res *= val;
	return (res);
}

Fixed::Fixed(void): val(0)
{
}

Fixed::Fixed(int fixed)
{
	this->val = fixed << this->lit;
}

Fixed::Fixed(float fixed)
{
	int pow = power(2, this->lit);

	this->val = roundf(fixed * pow);
}
Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::~Fixed(void)
{
}

Fixed &Fixed::operator=(Fixed const &other)
{
	this->val = other.val;
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return (this->val);
}

void	Fixed::setRawBits(const int raw)
{
	this->val = raw;
}

int	Fixed::toInt( void ) const
{
	return (this->val >> this->lit);
}

float	Fixed::toFloat( void ) const
{
	int		pow = power(2, this->lit);
	float	result = (float)this->val / pow;

	return (result);
}

std::ostream &operator<<(std::ostream &stream, Fixed const &instance)
{
	stream << instance.toFloat();
	return (stream);
}

//comparazioni

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (other > *this);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (!(*this < other));
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (!(*this > other));
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (other.getRawBits() == this->getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (!(other == *this));
}

//operazioni

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	result(this->toFloat() * other.toFloat());

	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	result(this->toFloat() / other.toFloat());

	return (result);
}

//post/pre fix operator

Fixed& Fixed::operator++(void)
{
	this->val++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->val--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	++(*this);
	return (old);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	--(*this);
	return (old);
}

//max min func

Fixed		&Fixed::min(Fixed &first, Fixed &other)
{
	if (first < other)
		return (first);
	return (other);
}

const Fixed		&Fixed::min(const Fixed &first, const Fixed &other)
{
	if (first < other)
		return (first);
	return (other);
}

Fixed		&Fixed::max(Fixed &first, Fixed &other)
{
	if (first > other)
		return (first);
	return (other);
}

const Fixed		&Fixed::max(const Fixed &first, const Fixed &other)
{
	if (first > other)
		return (first);
	return (other);
}