#include "ScalarConverter.hpp"

void	ScalarConverter::convert(std::string str)
{
	std::cout << std::fixed << std::setprecision(1);
	std::string specialTypes[6] = 
	{
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};
	int		int_cast = 0;
	float	float_cast = 0;
	double	double_cast = 0;
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
	{
		std::cout << "char: '" << str[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(str[0] )<< ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
		return ;
	}
	for (int i = 0; i < 6; i++)
	{
		if (specialTypes[i] == str)
		{
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << "impossible" << std::endl;
			if (str == "nan" || str == "nanf")
			{
				std::cout << "float: " << "nanf" << std::endl;
				std::cout << "double: " << "nan" << std::endl;
			}
			else
			{
				std::cout << "float: " << specialTypes[i] << std::endl;
				std::cout << "double: " << specialTypes[i] << std::endl;
			}

			return ;
		}
	}
	int_cast = std::atoi(str.c_str());
	if (str[str.length() - 1] == 'f')
	{
		float_cast = std::atof(str.c_str());
		double_cast = static_cast<double>(float_cast);
	}
	else
	{
		double_cast = std::atof(str.c_str());
		float_cast = static_cast<float>(double_cast);
	}
	if (std::isprint(int_cast))
		std::cout << "char: '" << static_cast<char>(int_cast) << "'" << std::endl;
	else
		std::cout << "char: " << "not displayable" << std::endl;
	std::cout << "int: " << int_cast << std::endl;
	std::cout << "float: " << float_cast<< "f" << std::endl;
	std::cout << "double: " << double_cast << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::~ScalarConverter()
{
}