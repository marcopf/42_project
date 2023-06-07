#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
{
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	this->attackDamage = FragTrap::attackDamage;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	std::cout << "DiamondTrap " << this->name << " has been assembled\n";
}

DiamondTrap::DiamondTrap(void)
{
	this->name = "";
	ClapTrap::name = "default_clap_name";
	this->attackDamage = FragTrap::attackDamage;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	std::cout << "DiamondTrap " << this->name << " has been assembled\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " has been destroyed\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& cpy)
{
	*this = cpy;
}

void	DiamondTrap::operator=(const DiamondTrap& cpy)
{
	this->name = cpy.name;
	this->attackDamage = cpy.attackDamage;
	this->hitPoints = cpy.hitPoints;
	this->energyPoints = cpy.energyPoints;
}

void	DiamondTrap::attack(std::string name)
{
	ScavTrap::attack(name);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "hi my name is " << this->name << " and my clap_trap name is " << ClapTrap::name << std::endl;
}

