#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Materia default constructor has been called" << std::endl;
}

AMateria::AMateria(std::string const & type): type(type)
{
	
}

AMateria::AMateria(const AMateria& obj)
{
	std::cout << "Materia copy constructor has been called" << std::endl;
	*this = obj;
}

AMateria& AMateria::operator= (const AMateria& obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria is used on " << target.getName() << std::endl;
}