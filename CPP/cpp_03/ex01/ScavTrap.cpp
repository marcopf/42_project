#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->attackDamage = 20;
	this->hitPoints = 100;
	this->energyPoints = 50;
	std::cout << "ScavTrap " << this->name << " has been built\n";
}

ScavTrap::ScavTrap(void)
{
	this->name = "";
	this->attackDamage = 20;
	this->hitPoints = 100;
	this->energyPoints = 50;
	std::cout << "ScavTrap " << "Default" << " has been built\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " has been destroyed\n";
}

ScavTrap::ScavTrap(const ScavTrap& cpy)
{
	*this = cpy;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ClapTrap " << this->getName() << " is now in gate keeper mode!\n";
}

void	ScavTrap::operator=(const ScavTrap& cpy)
{
	this->name = cpy.name;
	this->attackDamage = cpy.attackDamage;
	this->hitPoints = cpy.hitPoints;
	this->energyPoints = cpy.energyPoints;
}