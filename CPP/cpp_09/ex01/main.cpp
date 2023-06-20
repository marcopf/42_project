#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: bad arguments\n";
		return (1);
	}
	RPN test(argv[1]);
}