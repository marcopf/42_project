#include "Harl.hpp"

typedef	void	(Harl::*funcs)(void);

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!\n\n";
}
void	Harl::info()
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}
void	Harl::warning()
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n\n";
}
void	Harl::error()
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n\n";
}

void	Harl::complain(std::string level)
{
	int	val = -1;
	funcs arr[] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string list[] = {
		"debug",
		"info",
		"warning",
		"error"
	};
	//much better way
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (level == list[i])
	// 	{
	// 		for (int j = i; j < 4; j++)
	// 			(this->*(arr[j]))();
	// 		return ;
	// 	}
	// }
	for (int i = 0; i < 4; i++)
	{
		if (level == list[i])
			val = i;
	}
	switch (val)
	{
		case 0:
			for (int j = val; j < 4; j++)
				(this->*(arr[j]))();
			break;
		case 1:
			for (int j = val; j < 4; j++)
				(this->*(arr[j]))();
			break;
		case 2:
			for (int j = val; j < 4; j++)
				(this->*(arr[j]))();
			break;
		case 3:
			for (int j = val; j < 4; j++)
				(this->*(arr[j]))();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}