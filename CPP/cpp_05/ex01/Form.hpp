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
	const int			GradeTooHighException;
	const int			GradeTooLowException;

public:
	//functions
	void		beSigned(Bureaucrat &bur);
	void		sign_form(Bureaucrat &bur);
	int			set_grade(int grade)const;
	std::string	get_name(void)const;
	bool		isSigned(void)const;
	int			get_grade_to_sign(void)const;
	int			get_grade_to_execute(void)const;

	//operator overload
	friend std::ostream	&operator<<(std::ostream &os, const Form &other);
	Form				&operator=(const Form &other);

	//constructor
	Form(std::string name, int grade_to_sign, int grade_to_execute);
	Form(const Form &other);
	Form(void);
	~Form();
};

#endif