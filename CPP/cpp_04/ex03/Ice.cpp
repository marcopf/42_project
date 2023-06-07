#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "ice set\n";
}

Ice::Ice(const Ice &other) :AMateria("ice")
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

void	Ice::use(ICharacter &other)
{
	std::cout << "* heals " << other.getName() << "'s wounds *" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice decostructor\n";
}