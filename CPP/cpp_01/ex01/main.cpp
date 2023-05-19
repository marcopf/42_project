#include "Zombie.hpp"

int main(int argc, char **argv)
{
	Zombie	*horde = NULL;
	int		n;

	if (argc != 3)
	{
		std::cout << "bad argument" << std::endl;
		return (0);
	}
	n = atoi(argv[1]);
	if (n == 0)
	{
		std::cout << "no zombie in horde" << std::endl;
		return (0);
	}
	horde = horde->zombieHorde(n, argv[2]);
	for (int i = 0; i < n; i++)
	{
		horde[i].setName(argv[2]);
		horde[i].announce();
	}
	delete [] horde;
}