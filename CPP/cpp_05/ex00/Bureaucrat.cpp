#include "Bureaucrat.hpp"

std::string	Bureaucrat::get_name(void)const
{
	return (this->name);
}

int 		Bureaucrat::get_grade(void)const
{
	return (this->grade);
}

void 		Bureaucrat::set_grade(int grade)
{
	try
	{
		if (grade < 1)
			throw (-1);
		else if (grade > 150)
			throw (-2);
		this->grade = grade;
	}
	catch (int e)
	{
		if (e == Bureaucrat::GradeTooLowException)
			std::cerr << "Error: grade to low..." << std::endl;
		else if (e == Bureaucrat::GradeTooHighException)
			std::cerr << "Error: grade to high..." << std::endl;
	}
}

void		Bureaucrat::increment_grade(void)
{
		set_grade(get_grade() - 1);
}

void		Bureaucrat::decrement_grade(void)
{
		set_grade(get_grade() + 1);
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bur)
{
	os << bur.get_name() << ", my grade is " << bur.get_grade() << std::endl;
	return (os);
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bur)
{
	std::cout << "BUREAUCRAT assign operator" << std::endl;
	this->grade = bur.grade;
	return (*this);
}

Bureaucrat::Bureaucrat(void) : name (""), GradeTooHighException(-1), GradeTooLowException(-2)
{
	std::cout << "BUREAUCRAT default built" << std::endl;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), GradeTooHighException(-1), GradeTooLowException(-2)
{
	std::cout << "BUREAUCRAT built" << std::endl;
	set_grade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur) : GradeTooHighException(-1), GradeTooLowException(-2)
{
	std::cout << "BUREAUCRAT built from another" << std::endl;
	*this = bur;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "BUREAUCRAT destroyed" << std::endl;
}