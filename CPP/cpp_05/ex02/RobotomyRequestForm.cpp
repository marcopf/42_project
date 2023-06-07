#include "RobotomyRequestForm.hpp"

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	srand((unsigned)time(NULL));
	if (executor.get_grade() <= this->get_grade_to_execute())
	{
		std::cout << "* DRILLING NOISES *\n";
		if (rand() % 2 == 0)
			std::cout << this->target << " has been robotomized successfully\n";
		else
			std::cout << this->target << " robotomize ended in failure\n";
	}
	else
		std::cout << "your grade is to low can't execute\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	(void)other;
	std::cout << "RobotomyRequestForm assign called\n";
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("RobotomyRequestForm", 72, 45), target(other.target)
{
	std::cout << "RobotomyRequestForm has been copy created\n";
	*this = other;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm has been created\n";
}

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), target("")
{
	std::cout << "RobotomyRequestForm has been created\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm has been destroyed\n";
}