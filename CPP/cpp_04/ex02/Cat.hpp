#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal
{
protected:
	std::string	_type;
	Brain		*_brain;
public:
	virtual void		makeSound(void)const;
	Cat(void);
	Cat(const Cat& other);
	virtual Brain	*getBrain()const;
	Cat	&operator=(const Cat &other);
	~Cat(void);
	virtual const std::string	&getType(void) const;
};

#endif