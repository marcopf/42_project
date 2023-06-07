#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include <string>

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice &other);
	Ice const	&operator=(const Ice &other);
	virtual AMateria* clone(void)const;
	virtual void use(ICharacter& target);
	~Ice();
};

#endif