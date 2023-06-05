#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>

class ScalarConverter
{
private:
	/* data */
public:
	void	convert(std::string str);
	ScalarConverter &operator=(const ScalarConverter &other);
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter(void);
	~ScalarConverter();
};

bool	isPrint(int n);

#endif