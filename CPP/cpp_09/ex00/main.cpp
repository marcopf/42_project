#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange test;

	if (argc != 2)
		std::cout << "Error: bad arguments\n";
	test.loadFile(argv[1]);
	test.exchange();
}