#include "Character.hpp"

Character::Character(void)
{
	std::cout << "new character is setted\n";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->name = "";
}

Character::Character(std::string const &name)
{
	std::cout << "new character is setted\n";
	*this = Character();
	this->name = name;
	return ;
}

Character::Character(const Character &other)
{
	std::cout << "new character is being copied\n";
	*this = other;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != 0)
			delete this->inventory[i];
	}
	std::cout << "character decostructor\n";
}

const Character &Character::operator=(const Character &other)
{
	std::cout << "new character is being copied with assignment operator\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != 0)
			delete this->inventory[i];
		this->inventory[i] = other.inventory[i];
	}
	this->name = other.name;
	return (*this);
}

void Character::equip(AMateria* m)
{
	std::cout << m->getType() << " materia equiped\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (this->inventory[idx])
		this->inventory[idx] = NULL;

}

void Character::use(int idx, ICharacter& target)
{
		this->inventory[idx]->use(target);
	unequip(idx);
}

std::string const	&Character::getName() const
{
	return (this->name);
}