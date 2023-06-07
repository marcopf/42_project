#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>


class Brain
{
protected:
public:
	std::string	ideas[100];
	Brain	&operator=(const Brain &other);
	Brain(const Brain &other);
	Brain(std::string ideas);
	Brain(void);
	~Brain();
};

#endif