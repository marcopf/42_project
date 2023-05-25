#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*inventory[4];
public:
	MateriaSource(void);
	MateriaSource(std::string const &name);
	MateriaSource(const MateriaSource &other);
	const MateriaSource	&operator=(const MateriaSource &other);
	~MateriaSource();
	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
};

#endif