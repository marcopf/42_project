
#include "Intern.hpp"


int main()
{
	Intern stagista;
	AForm *tmp;
	Bureaucrat bur("primo", 1);
	Bureaucrat nuovo("nuovo", 130);

	tmp = stagista.makeForm("shrubbery creation", "marco");
	tmp->execute(bur);
	delete tmp;
	tmp = stagista.makeForm("robotomy request", "marco");
	tmp->execute(bur);
	delete tmp;
	tmp = stagista.makeForm("presidential pardon", "marco");
	tmp->execute(bur);
	tmp = stagista.makeForm("presidential", "marco");
	delete tmp;
	std::cout << "\n\n";
	tmp = stagista.makeForm("shrubbery creation", "marco");
	tmp->execute(nuovo);
	delete tmp;
	tmp = stagista.makeForm("robotomy request", "marco");
	tmp->execute(nuovo);
	delete tmp;
	tmp = stagista.makeForm("presidential pardon", "marco");
	tmp->execute(nuovo);
	tmp = stagista.makeForm("presidential", "marco");
	delete tmp;
}