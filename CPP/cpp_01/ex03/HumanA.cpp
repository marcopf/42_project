#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& wep)
{
	this->name = name;
	this->weapon = &wep;
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}