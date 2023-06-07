#include "Bureaucrat.hpp"
#include "AForm.hpp"

void	Bureaucrat::executeForm(AForm const &form)
{
	form.execute(*this);
}

void	Bureaucrat::signForm(AForm &form)
{
	if (form.get_grade_to_sign() < this->get_grade())
	{
		std::cout << this->get_name() << " couldn't sign " << form.get_name() << " grade too low..." << std::endl;
		return ;
	}
	form.sign_form(*this);
}

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
			throw (Bureaucrat::GradeTooHighException());
		else if (grade > 150)
			throw (Bureaucrat::GradeTooLowException());
		this->grade = grade;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
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

Bureaucrat::Bureaucrat(void) : name ("")
{
	std::cout << "BUREAUCRAT default built" << std::endl;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	std::cout << "BUREAUCRAT built" << std::endl;
	set_grade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur)
{
	std::cout << "BUREAUCRAT built from another" << std::endl;
	*this = bur;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "BUREAUCRAT destroyed" << std::endl;
}