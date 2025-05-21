#include "MateriaSource.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	*this = obj;
}

MateriaSource& MateriaSource::operator= (const MateriaSource& obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < 4; i++)
		{
			slots[i] = obj.slots[i];
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete slots[i];
		slots[i] = NULL;
	}
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
	std::cout << "Learn inventory is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (slots[i] && slots[i]->getType() == type)
		{
			return slots[i]->clone();
		}
	}
	return NULL;
}
