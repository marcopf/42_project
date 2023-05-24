#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria constructed\n";
	this->type = type;
}


std::string const &AMateria::getType(void)const
{
	return (this->type);
}


AMateria::~AMateria()
{
}