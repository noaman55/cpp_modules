#include "MateriaSource.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}

MateriaSource::~MateriaSource()
{
}

void MateriaSource::learnMateria(AMateria* ptr)
{
	for (int i = 0; i < 4; i++)
	{
		if (slots[i] == NULL)
		{
			slots[i] = ptr;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (slots[i] && slots[i]->getType() == type)
			return slots[i];
	}
	return NULL;
}
