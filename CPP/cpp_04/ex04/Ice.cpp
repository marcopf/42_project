#include "Ice.hpp"

Ice::Ice(void) : AMateria("Ice")
{
	std::cout << "ice set\n";
}

Ice::Ice(const Ice &other) :AMateria("Ice")
{
	std::cout << "copy constructor\n";
	*this = other;
}

Ice const	&Ice::operator=(const Ice &other)
{
	std::cout << "copy operator\n";
	this->type = other.type;
	return (*this);
}

AMateria *Ice::clone(void)const
{
	return (new Ice(*this));
}
