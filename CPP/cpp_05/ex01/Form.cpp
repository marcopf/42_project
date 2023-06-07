#include "Form.hpp"
#include "Bureaucrat.hpp"

void	Form::sign_form(Bureaucrat &bur)
{
	if (!this->isSigned())
	{
		std::cout << bur.get_name() << " signed " << this->get_name() << std::endl;
		this->is_signed = true;
		return ;
	}
	else
		std::cout << bur.get_name() << " couldn't sign " << this->get_name() << "(already signed)" << std::endl;
}

void	Form::check_grade(void)const
{
	try
	{
		if (this->get_grade_to_execute() > 150 || this->get_grade_to_sign() > 150)
			throw Form::GradeTooLowException();
		if (this->get_grade_to_execute() < 1 || this->get_grade_to_sign() < 1)
			throw Form::GradeTooHighException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}


std::string	Form::get_name(void)const
{
	return (this->name);
}

int 		Form::get_grade_to_sign(void)const
{
	return (this->grade_to_sign);
}

int 		Form::get_grade_to_execute(void)const
{
	return (this->grade_to_execute);
}

bool 		Form::isSigned(void)const
{
	return (this->is_signed);
}

void	Form::beSigned(Bureaucrat &bur)
{
	if (this->grade_to_sign < bur.get_grade())
	{
		std::cout << bur.get_name() << " couldn't sign " << this->name << " grade too low..." << std::endl;
		return ;
	}
	sign_form(bur);
}

Form	&Form::operator=(const Form &other)
{
	this->is_signed = other.is_signed;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Form &other)
{
	os << other.get_name() << ", grade to sign: " << other.get_grade_to_sign() << ", grade to execute: " << other.get_grade_to_execute() << std::endl;
	return (os);
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	check_grade();
	this->is_signed = false;
}

Form::Form(void) : name(""), grade_to_sign(150), grade_to_execute(150)
{
	this->is_signed = false;
}

Form::Form(const Form &other) : name(other.name), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
	this->is_signed = other.is_signed;
}

Form::~Form()
{
}