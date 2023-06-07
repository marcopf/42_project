#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure set\n";
}

Cure::Cure(const Cure &other) :AMateria("cure")
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

void	Cure::use(ICharacter &other)
{
	std::cout << "* shoots an ice bolt at " << other.getName() << " *" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure decostructor\n";
}