#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include <string>

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(const Cure &other);
	Cure const	&operator=(const Cure &other);
	virtual AMateria* clone()const;
	virtual void use(ICharacter& target)const;
	~Cure();
};

#endif