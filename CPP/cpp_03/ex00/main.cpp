#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap1("clap");

	clap1.attack("handsome Jack");
	clap1.takeDamage(6);
	clap1.beRepaired(4);
	clap1.takeDamage(3);
	clap1.beRepaired(8);
	clap1.takeDamage(17);
}