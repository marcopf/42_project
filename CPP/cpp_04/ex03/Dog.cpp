#include "Dog.hpp"

Dog::Dog(void)
{
	this->_type = "Dog";
	std::cout << "dog is born!\n";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& other)
{
	std::cout << "Dog is being copied!\n";
	*this = other;
}

Dog::~Dog()
{
	std::cout << "Dog " << this->_type << " is died :(\n";
	delete this->_brain;
}

void		Dog::makeSound(void)const
{
	std::cout << "WOFF WOFF!!\n";
}

const std::string	&Dog::getType(void) const
{
	return (this->_type);
}