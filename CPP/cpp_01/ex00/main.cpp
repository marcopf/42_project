#include "Zombie.hpp"

int main()
{
	Zombie	*z1 = NULL, *z2 = NULL, *z3 = NULL;

	z1 = z1->newZombie("marco");
	z2 = z2->newZombie("mario");
	z3 = z3->newZombie("luigi");
	z1->announce();
	z2->announce();
	z3->announce();
	z1->randomChump("giovanni");
	z2->randomChump("luca");
	z3->randomChump("alessandro");
	delete(z1);
	delete(z2);
	delete(z3);
}