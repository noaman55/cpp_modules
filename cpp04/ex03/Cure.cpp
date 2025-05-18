#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure default constructor has been called!" << std::endl;
}

Cure::Cure(const Cure& obj)
{
	std::cout << "Cure copy constructor has been called!" << std::endl;
	*this = obj;
}

Cure& Cure::operator= (const Cure& obj)
{
	std::cout << "Cure assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor has been called!" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}