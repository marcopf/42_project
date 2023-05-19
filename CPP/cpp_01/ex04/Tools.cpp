#include "Tools.hpp"

Tools::Tools(std::string path, std::string to_find, std::string to_replace)
{
	this->to_find = to_find;
	this->to_replace = to_replace;
	this->path = path;
}

Tools::~Tools()
{
}

std::string	Tools::fileToStr(std::string path)
{
	std::ifstream t(path);
	std::stringstream buffer;
	buffer << t.rdbuf();
	t.close();
	return (buffer.str());
}

void	Tools::makeReplace(std::string& file_str)
{
	int	index = 0;

	file_str = fileToStr(this->path);
	while (42)
	{
		index = file_str.find(this->to_find, index);
		if (index == std::string::npos)
			break ;
		file_str.erase(index, this->to_find.length());
		file_str.insert(index, this->to_replace);
	}
}

void	Tools::writeToFile(std::string str)
{
	std::ofstream	file(path + ".replace");

	file << str;
	file.close();
}