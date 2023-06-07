#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <sstream>

class Form;

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;

public:
	//functions
	void				signForm(Form &form);
	int					get_grade(void)const;
	std::string			get_name(void)const;
	void				set_grade(int grade);
	void				increment_grade(void);
	void				decrement_grade(void);

	//operator overload
	Bureaucrat			&operator=(const Bureaucrat &bur);

	//constructors
	Bureaucrat(std::string name, int grade);
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat &bur);
	~Bureaucrat();
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

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bur);

#endif