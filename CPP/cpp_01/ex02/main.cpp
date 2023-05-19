#include <iostream>

int main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "str memory address: ";
	std::cout << &str << std::endl;
	std::cout << "stringPTR value: ";
	std::cout << stringPTR << std::endl;
	std::cout << "stringREF memory address: ";
	std::cout << &stringREF << std::endl << std::endl;

	std::cout << "str value: ";
	std::cout << str << std::endl;
	std::cout << "stringPTR pointed value: ";
	std::cout << *stringPTR << std::endl;
	std::cout << "stringREF value: ";
	std::cout << stringREF << std::endl;
}