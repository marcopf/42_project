#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->attackDamage = 0;
	this->energyPoints = 10;
	this->hitPoints = 10;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& cpy)
{
	this->name = cpy.name;
	this->attackDamage = cpy.attackDamage;
	this->energyPoints = cpy.energyPoints;
	this->hitPoints = cpy.attackDamage;
	return (*this);
}

ClapTrap::ClapTrap(void)
{
	this->name = "";
	this->attackDamage = 20;
	this->energyPoints = 50;
	this->hitPoints = 100;
}


ClapTrap::ClapTrap(const ClapTrap& cpy)
{
	*this = cpy;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->name << " has been destroyed\n";
}

void	ClapTrap::attack(const std::string& name)
{
	if (energyPoints > 0)
	{
		std::cout << this->name << " attack " << name << " causing " << this->attackDamage << " points of damage!\n";
		this->energyPoints--;
	}
	else
		std::cout << this->name << "has no energy points left...\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int life = this->hitPoints - amount;

	if (life > 0)
	{
		std::cout << this->name << " has taken " << amount << " points of damage!\n";
		this->hitPoints -= amount;
	}
	else
		std::cout << this->name << " has taken " << amount << " points of damage and is died...\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0)
	{
		std::cout << this->name << " is repairing himself taking back " << amount << " Hit points back!!\n";
		this->hitPoints += amount;
	}
	else
		std::cout << this->name << "has no energy points left...\n";
}