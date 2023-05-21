#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string		name;
	unsigned int 	hitPoints;
	unsigned int 	energyPoints;
	unsigned int 	attackDamage;

public:
	//ClapTrap(std::string name, int life, int energyPoints, int dmg);
	void		attack(const std::string& name);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	ClapTrap&	operator=(const ClapTrap& cpy);
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& cpy);
	~ClapTrap();
};

#endif
