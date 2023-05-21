#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->attackDamage = 30;
	this->hitPoints = 100;
	this->energyPoints = 100;
	std::cout << name << " has been assembled\n";
}

FragTrap::FragTrap(void)
{
	this->name = "";
	this->attackDamage = 30;
	this->hitPoints = 100;
	this->energyPoints = 100;
	std::cout << name << " has been assembled\n";
}

FragTrap::~FragTrap()
{
}

FragTrap::FragTrap(const FragTrap& cpy)
{
	*this = cpy;
}

void	FragTrap::operator=(const FragTrap& cpy)
{
	this->name = cpy.name;
	this->attackDamage = cpy.attackDamage;
	this->hitPoints = cpy.hitPoints;
	this->energyPoints = cpy.energyPoints;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "positive high five request sent on stdout...\n";
}