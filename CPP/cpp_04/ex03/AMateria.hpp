#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string type;
public:
	AMateria(std::string const &type);
	std::string const	&getType() const; //Returns the materia type
	virtual AMateria*	clone(void) const = 0;
	virtual void		use(ICharacter& target) = 0;
	virtual ~AMateria();
};

#endif