#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

class ShrubberyCreationForm : public AForm
{
private:
	const std::string target;
public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm(void);
	~ShrubberyCreationForm();
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);
	virtual void	execute(const Bureaucrat &executor)const;
};

#endif