#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
protected:
	std::string	_type;
public:
	virtual void		makeSound(void)const ;
	Dog(void);
	Dog(const Dog& other);
	~Dog(void);
	virtual const std::string	&getType(void) const;
};

#endif