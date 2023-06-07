#include "Intern.hpp"

AForm	*Intern::makeForm(std::string type, std::string target)
{
	AForm *form;

	if (type == "robotomy request")
		form = new RobotomyRequestForm(target);
	else if (type == "shrubbery creation")
		form = new ShrubberyCreationForm(target);
	else if (type == "presidential pardon")
		form = new PresidentialPardonForm(target);
	else
	{
		std::cout << "sorry i can't make this form\n";
		return (NULL);
	}
	return (form);
}

Intern	&Intern::operator=(const Intern &other)
{
	std::cout << "Intern is assigned\n";
	this->form_name = other.form_name;
	this->target = other.target;
	return (*this);
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern is copied\n";
	*this = other;
}

Intern::Intern(std::string form_name, std::string target)
{
	std::cout << "Intern is arrived\n";
	this->form_name = form_name;
	this->target = target;
}

Intern::Intern(void)
{
	std::cout << "Intern is arrived\n";
	this->target = "";
	this->form_name = "";
}

Intern::~Intern()
{
	std::cout << "Intern is gone\n";
}