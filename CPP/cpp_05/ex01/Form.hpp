#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <sstream>

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				is_signed;
	const int			grade_to_sign;
	const int			grade_to_execute;

public:
	//functions
	void		beSigned(Bureaucrat &bur);
	void		sign_form(Bureaucrat &bur);
	void			check_grade(void)const;
	std::string	get_name(void)const;
	bool		isSigned(void)const;
	int			get_grade_to_sign(void)const;
	int			get_grade_to_execute(void)const;

	//operator overload
	Form				&operator=(const Form &other);

	//constructor
	Form(std::string name, int grade_to_sign, int grade_to_execute);
	Form(const Form &other);
	Form(void);
	~Form();
public:
	class GradeTooHighException : public std::exception
	{
		virtual const char *what()const throw()
		{
			return ("Error: grade to high");
		}
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what()const throw()
		{
			return ("Error: grade to low");
		}
	};
};

std::ostream	&operator<<(std::ostream &os, const Form &other);

#endif