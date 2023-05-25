#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
protected:
	std::string	_type;
public:
	virtual void		makeSound(void)const;
	Cat(void);
	Cat(const Cat& other);
	~Cat(void);
	virtual const std::string	&getType(void) const;
};

#endif