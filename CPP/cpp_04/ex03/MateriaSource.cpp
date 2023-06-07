#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "materia constructed\n";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "materia source deconstructor\n";
	*this = other;
}

MateriaSource::~MateriaSource()
{
	std::cout << "inventory is now empty\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != 0)
			delete this->inventory[i];
	}
}

const MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "copy assignment operator executed\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != 0)
			delete this->inventory[i];
		this->inventory[i] = other.inventory[i];
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			std::cout << "materia " << m->getType() << " learned\n";
			break ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4 && this->inventory[i]; i++)
	{
		if (this->inventory[i]->getType() == type)
			return (this->inventory[i]->clone());
	}
	return (NULL);
}