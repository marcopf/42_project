#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits>

class ScalarConverter
{
public:
	static void	convert(std::string str);
private:
	ScalarConverter &operator=(const ScalarConverter &other);
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter(void);
	~ScalarConverter();
};

bool	isPrint(int n);

#endif