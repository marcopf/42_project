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

int	Form::set_grade(int grade)const
{
	try
	{
		if (grade > 150)
			throw (Form::GradeTooLowException);
		else if (grade < 1)
			throw (Form::GradeTooHighException);
	}
	catch (int e)
	{
		if (e == Form::GradeTooHighException)
			return (1);
		else if (e == Form::GradeTooLowException)
			return (150);
	}
	return (grade);
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
	try
	{
		if (this->grade_to_sign < bur.get_grade())
			throw (Form::GradeTooLowException);
	}
	catch (int e)
	{
		if (e == Form::GradeTooLowException)
			std::cout << bur.get_name() << " couldn't sign " << this->name << "(grade to low)" << std::endl;
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

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : name(name), GradeTooHighException(-1), GradeTooLowException(-2), grade_to_sign(this->set_grade(grade_to_sign)), grade_to_execute(this->set_grade(grade_to_execute))
{
	this->is_signed = false;
}

Form::Form(void) : name(""), grade_to_sign(150), grade_to_execute(150), GradeTooHighException(-1), GradeTooLowException(-2)
{
	this->is_signed = false;
}

Form::Form(const Form &other) : name(other.name), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute), GradeTooHighException(-1), GradeTooLowException(-2)
{
	this->is_signed = other.is_signed;
}

Form::~Form()
{
}