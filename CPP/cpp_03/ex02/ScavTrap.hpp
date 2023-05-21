#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	void		operator=(const ScavTrap& cpy);
	void		guardGate(void);
	ScavTrap(std::string name);
	ScavTrap(void);
	ScavTrap(const ScavTrap& cpy);
	~ScavTrap();
};



#endif