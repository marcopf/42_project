#include "PresidentialPardonForm.hpp"

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.get_grade() <= this->get_grade_to_execute())
		std::cout << "Informs that " << this->target << " has been pardoned by Zaphod Beeblebrox.\n";
	else
		std::cout << "your grade is to low can't execute\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	(void)other;
	std::cout << "PresidentialPardonForm assign called\n";
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("PresidentialPardonForm", 25, 5), target(other.target)
{
	std::cout << "PresidentialPardonForm has been copy created\n";
	*this = other;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm has been created\n";
}

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), target("")
{
	std::cout << "PresidentialPardonForm has been created\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm has been destroyed\n";
}