#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
public:
	virtual ~Animal(void);
	Animal			&operator=(const Animal &other);
	virtual void	makeSound(void) const = 0;
	virtual const std::string	&getType(void) const;
	virtual	Brain	*getBrain()const;
protected:
	std::string type;
};

#endif