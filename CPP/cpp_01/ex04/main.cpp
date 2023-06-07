#include "Tools.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "bad arguments\n";
		return (1);
	}
	Tools		tools(argv[1], argv[2], argv[3]);
	std::string	file_str;

	tools.makeReplace(file_str);
	tools.writeToFile(file_str);
}