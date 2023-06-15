#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <locale.h>
#include <time.h>

class BitcoinExchange
{
private:
	std::map<int, double> map;
	std::multimap<int, double> to_convert;
public:
	void	exchange(void);
	void	loadFile(char *str);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange(void);
	BitcoinExchange	&operator=(const BitcoinExchange &copy);
	~BitcoinExchange();
};

#endif