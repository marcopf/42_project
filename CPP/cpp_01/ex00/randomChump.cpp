#include "Zombie.hpp"

void	Zombie::randomChump(std::string name)
{
	Zombie	temp(name);

	temp.announce();
}