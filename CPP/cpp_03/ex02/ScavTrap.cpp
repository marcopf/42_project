#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->attackDamage = 20;
	this->hitPoints = 100;
	this->energyPoints = 50;
	std::cout << name << " has been assembled\n";
}

ScavTrap::ScavTrap(void)
{
	this->name = "";
	this->attackDamage = 20;
	this->hitPoints = 100;
	this->energyPoints = 50;
	std::cout << name << " has been assembled\n";
}

ScavTrap::~ScavTrap()
{
}

ScavTrap::ScavTrap(const ScavTrap& cpy)
{
	*this = cpy;
}

void	ScavTrap::guardGate(void)
{
	std::cout << this->getName() << " is now in gate keeper mode!\n";
}

void	ScavTrap::operator=(const ScavTrap& cpy)
{
	this->name = cpy.name;
	this->attackDamage = cpy.attackDamage;
	this->hitPoints = cpy.hitPoints;
	this->energyPoints = cpy.energyPoints;
}