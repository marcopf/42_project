#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	std::string	form_name;
	std::string target;

public:
	AForm	*makeForm(std::string type, std::string target);
	Intern(std::string form_name, std::string target);
	Intern(const Intern &other);
	Intern(void);
	~Intern();
	Intern	&operator=(const Intern &other);
};

#endif