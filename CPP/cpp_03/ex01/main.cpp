#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap1("marco");
	ScavTrap	scav("tester");

	clap1.attack("big enemy");
	clap1.beRepaired(1);
	clap1.takeDamage(20);
	scav.beRepaired(20);
	scav.attack("marco");
	scav.guardGate();
}