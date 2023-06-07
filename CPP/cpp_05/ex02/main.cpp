#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	erMeglio("erMeglio", 1), nuovo("nuovo", 137);
	AForm	*form;

	form = new RobotomyRequestForm("bender");
	form->execute(erMeglio);
	delete form;
	form = new ShrubberyCreationForm("marco");
	form->execute(erMeglio);
	delete form;
	form = new PresidentialPardonForm("luigi");
	form->execute(erMeglio);
	delete form;
	std::cout << "\n\n";
	form = new RobotomyRequestForm("bender");
	form->execute(nuovo);
	delete form;
	form = new ShrubberyCreationForm("marco");
	form->execute(nuovo);
	delete form;
	form = new PresidentialPardonForm("luigi");
	form->execute(nuovo);
	delete form;
}