#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

# include <iostream>

class WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &src);
	virtual ~WrongAnimal(void);
	WrongAnimal			&operator=(const WrongAnimal &other);
	virtual void	makeSound(void) const;
	virtual const std::string	&getType(void) const;
protected:
	std::string type;
};

#endif