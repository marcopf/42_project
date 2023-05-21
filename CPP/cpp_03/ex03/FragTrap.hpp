#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	/* data */
public:
	void		operator=(const FragTrap& cpy);
	void		highFiveGuys(void);
	FragTrap(std::string name);
	FragTrap(void);
	FragTrap(const FragTrap& cpy);
	~FragTrap();
};

#endif