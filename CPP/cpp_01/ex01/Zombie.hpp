#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "iostream"

	class Zombie
	{
	private:
		std::string	_name;
	public:
		Zombie	*newZombie(std::string name);
		Zombie	*zombieHorde(int n, std::string name);
		void	randomChump(std::string name);
		void	setName(std::string name);
		void	announce(void);
		Zombie(std::string name);
		Zombie(void);
		~Zombie();
	};

#endif