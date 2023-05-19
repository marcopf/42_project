#ifndef TOOLS_HPP
# define TOOLS_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Tools
{
private:
	std::string	to_find;
	std::string	to_replace;
	std::string	path;
	std::string fileToStr(std::string path);
	
public:
	void		writeToFile(std::string str);
	void		makeReplace(std::string& file_str);
	Tools(std::string path, std::string to_find, std::string to_replace);
	~Tools();
};

#endif