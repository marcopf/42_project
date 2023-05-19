#include "Zombie.hpp"

Zombie	*Zombie::zombieHorde(int n, std::string name)
{
	Zombie	*horde;

	horde = new Zombie[n];
	return (horde);
}