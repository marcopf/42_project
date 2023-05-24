#include "Cure.hpp"

Cure::Cure(void) : AMateria("Cure")
{
	std::cout << "Cure set\n";
}

Cure::Cure(const Cure &other) :AMateria("Cure")
{
	std::cout << "copy constructor\n";
	*this = other;
}

Cure const	&Cure::operator=(const Cure &other)
{
	std::cout << "copy operator\n";
	this->type = other.type;
	return (*this);
}

AMateria *Cure::clone(void)const
{
	return (new Cure(*this));
}
