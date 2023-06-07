#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat sig1("marco", 110);
	Bureaucrat sig2("giovanni", 1);
	Form		f1("tasse", 10, 5), f2("allegato3", 110, 30);

	f1.beSigned(sig1);
	f1.beSigned(sig2);
	f2.beSigned(sig1);
	f2.beSigned(sig2);
}