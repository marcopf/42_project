#include "Cat.hpp"

Cat::Cat(void)
{
	this->_type = "Cat";
	std::cout << "cat is born!\n";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& other)
{
	std::cout << "Cat is being copied!\n";
	*this = other;
	delete this->_brain;
}

Cat::~Cat()
{
	std::cout << "Cat " << this->_type << " is died :(\n";
}

void	Cat::makeSound(void)const
{
	std::cout << "MEAOWWWWW!!\n" << this->_brain->ideas[10];
}

const std::string	&Cat::getType(void) const
{
	return (this->_type);
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "a Cat is being copy assigned\n";
	this->type = other.type;
	this->_brain = new Brain();
	return (*this);
}

Brain	*Cat::getBrain()const
{
	return (this->_brain);
}