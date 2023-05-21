#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->attackDamage = 30;
	this->hitPoints = 100;
	this->energyPoints = 100;
	std::cout << "FragTrap " << name << " has been assembled\n";
}

FragTrap::FragTrap(void)
{
	this->name = "";
	this->attackDamage = 30;
	this->hitPoints = 100;
	this->energyPoints = 100;
	std::cout << "FragTrap default has been assembled\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " has been destroyed\n";
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

void	FragTrap::highFiveGuys(void)
{
	std::cout << "positive high five request sent on stdout...\n";
}