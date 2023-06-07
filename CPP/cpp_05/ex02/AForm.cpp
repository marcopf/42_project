#include "AForm.hpp"
#include "Bureaucrat.hpp"

void	AForm::sign_form(Bureaucrat &bur)
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

void	AForm::check_grade(void)const
{
	try
	{
		if (this->get_grade_to_execute() > 150 || this->get_grade_to_sign() > 150)
			throw AForm::GradeTooLowException();
		if (this->get_grade_to_execute() < 1 || this->get_grade_to_sign() < 1)
			throw AForm::GradeTooHighException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}


std::string	AForm::get_name(void)const
{
	return (this->name);
}

int 		AForm::get_grade_to_sign(void)const
{
	return (this->grade_to_sign);
}

int 		AForm::get_grade_to_execute(void)const
{
	return (this->grade_to_execute);
}

bool 		AForm::isSigned(void)const
{
	return (this->is_signed);
}

void	AForm::beSigned(Bureaucrat &bur)
{
	if (this->grade_to_sign < bur.get_grade())
	{
		std::cout << bur.get_name() << " couldn't sign " << this->name << " grade too low..." << std::endl;
		return ;
	}
	sign_form(bur);
}

AForm	&AForm::operator=(const AForm &other)
{
	this->is_signed = other.is_signed;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const AForm &other)
{
	os << other.get_name() << ", grade to sign: " << other.get_grade_to_sign() << ", grade to execute: " << other.get_grade_to_execute() << std::endl;
	return (os);
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute) : name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	check_grade();
	this->is_signed = false;
}

AForm::AForm(void) : name(""), grade_to_sign(150), grade_to_execute(150)
{
	this->is_signed = false;
}

AForm::AForm(const AForm &other) : name(other.name), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
	this->is_signed = other.is_signed;
}

AForm::~AForm()
{
}