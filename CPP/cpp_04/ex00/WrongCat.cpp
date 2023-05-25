#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->_type = "WrongCat";
	std::cout << "WrongCat is born!\n";
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "WrongCat is being copied!\n";
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << this->_type << " is died :(\n";
}

void	WrongCat::makeSound(void)const
{
	std::cout << "WRONG MEAOWWWWW!!\n";
}

const std::string	&WrongCat::getType(void) const
{
	return (this->_type);
}