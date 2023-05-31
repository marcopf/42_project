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
	const int			GradeTooHighException;
	const int			GradeTooLowException;

public:
	//functions
	void				signForm(Form &form);
	int					get_grade(void)const;
	std::string			get_name(void)const;
	void				set_grade(int grade);
	void				increment_grade(void);
	void				decrement_grade(void);

	//operator overload
	friend std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bur);
	Bureaucrat			&operator=(const Bureaucrat &bur);

	//constructors
	Bureaucrat(std::string name, int grade);
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat &bur);
	~Bureaucrat();
};

#endif