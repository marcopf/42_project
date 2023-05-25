#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
protected:
	std::string	_type;
public:
	virtual void		makeSound(void)const;
	WrongCat(void);
	WrongCat(const WrongCat& other);
	~WrongCat(void);
	virtual const std::string	&getType(void) const;
};

#endif