#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
	void		operator=(const DiamondTrap& cpy);
	void		attack(std::string name);
	void		whoAmI(void);

	DiamondTrap(std::string name);
	DiamondTrap(void);
	DiamondTrap(const DiamondTrap& cpy);
	~DiamondTrap();
};

#endif