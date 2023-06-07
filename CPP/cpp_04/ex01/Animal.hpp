#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
public:
	Animal(void);
	Animal(const Animal &src);
	virtual ~Animal(void);
	virtual Brain	*getBrain()const = 0;
	Animal			&operator=(const Animal &other);
	virtual void	makeSound(void) const;
	virtual const std::string	&getType(void) const;
protected:
	std::string type;
};

#endif