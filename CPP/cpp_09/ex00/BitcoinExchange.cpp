#include "BitcoinExchange.hpp"

int	getIntDate(std::string date)
{
	std::stringstream	str;
	int	d, m, y, flag = 1;

	str.str(date);
	y = atoi(date.substr(0, 4).c_str());
	m = atoi(date.substr(5, 6).c_str());
	if (m > 12)
		flag = 0;
	d = atoi(date.substr(8, 9).c_str());
	if (d > 31)
		flag = 0;
	if (flag)
		return ((y * 10000) + (m * 100) + d);
	return (((y * 10000) + (m * 100) + d) * -1);
}

void	printDate(int n)
{
	if (n < 0)
		n *= -1;
	int d = n % 100, m = (n % 10000) / 100, y = n / 10000;
	std::cout << y << "-" << m << "-" << d << " ";
}

BitcoinExchange::BitcoinExchange(void)
{
	std::string temp, date, rate;
	int				int_date;	
	std::ifstream	myfile;

	myfile.open("data.csv");
	if (myfile.fail())
	{
		std::cout << "Error: could not open file\n";
		exit(1);
	}
	std::getline(myfile, temp, '\n');
	while (std::getline(myfile, temp, '\n'))
	{
		date = temp.substr(0, temp.find(','));
		int_date = getIntDate(date);
		rate = temp.substr(temp.find(',') + 1, temp.size());

		this->map.insert(std::pair<int, double>(int_date, atof(rate.c_str())));
	}
}


void	BitcoinExchange::loadFile(char *str)
{
	std::ifstream			file;
	std::string				temp, date, qty;
	int						int_date;

	file.open(str);
	if (file.fail())
	{
		std::cout << "Error: could not open file " << str << std::endl;
		exit(1);
	}
	std::getline(file, temp);
	while (std::getline(file, temp, '\n'))
	{
		if (temp.find('|') != std::string::npos)
			date = temp.substr(0, temp.find('|') - 1);
		else
		{
			date = temp;
			qty = -1;
			int_date = getIntDate(date);
			this->to_convert.insert(std::pair<int, double>(int_date, atof(qty.c_str())));
			continue ;
		}
		int_date = getIntDate(date);
		qty = temp.substr(temp.find('|') + 2, temp.size());
		this->to_convert.insert(std::pair<int, double>(int_date, atof(qty.c_str())));
	}
}

int	errorManager(std::map<int, double>::iterator it)
{
	int i = 0;

	if (it->first < 0)
	{
		std::cout << "Error: bad Input => ";
		printDate(it->first);
		std::cout << std::endl;
		i++;
	}
	else if (it->second <= 0)
	{
		std::cout << "Error: not a positive number\n";
		i++;
	}
	else if (it->second >= 2147483648)
	{
		std::cout << "Error: too large number\n";
		i++;
	}
	return (i);
}

void	BitcoinExchange::exchange(void)
{
	for (std::map<int, double>::iterator it = this->to_convert.begin(); it != this->to_convert.end(); it++)
	{
		int	counter_b = 0, counter_f = 0;
		if (errorManager(it))
			continue ;
		if (this->map.find(it->first) != this->map.end())
		{
			printDate(it->first);
			std::cout << "=> qty: " << it->second << "	| " << "rate: " << this->map.find(it->first)->second << " = " << this->map.find(it->first)->second * it->second << std::endl;
		}
		else
		{
			for (std::map<int, double>::iterator itm = this->map.begin(); itm != this->map.end(); itm++)
			{
				if (itm->first >= it->first)
				{
					counter_f = itm->first - it->first;
					break ;
				}
			}
			for (std::map<int, double>::iterator itm = --this->map.end(); itm != this->map.begin(); itm--)
			{
				if (itm->first <= it->first)
				{
					counter_b = it->first - itm->first;
					break ;
				}
			}
			printDate(it->first);
			if (counter_b < counter_f)
				std::cout << "=> qty: " << it->second << "	| " << "rate: " << this->map.find(it->first - counter_b)->second << " = " << this->map.find(it->first - counter_b)->second * it->second << std::endl;
			else
				std::cout << "=> qty: " << it->second << "	| " << "rate: " << this->map.find(it->first + counter_f)->second << " = " << this->map.find(it->first + counter_f)->second * it->second << std::endl;
		}
	}
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	this->map = copy.map;
	this->to_convert = copy.to_convert;
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
}