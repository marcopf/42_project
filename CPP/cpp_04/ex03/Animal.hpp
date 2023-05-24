#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
public:
	virtual ~Animal(void);
	Animal			&operator=(const Animal &other);
	virtual void	makeSound(void) const;
	virtual const std::string	&getType(void) const;
protected:
	std::string type;
};

#endif