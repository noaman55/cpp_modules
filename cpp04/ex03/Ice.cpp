#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
    std::cout << "Ice default constructor has been called!" << std::endl;
}

Ice::Ice(const Ice& obj)
{
	std::cout << "Ice copy constructor has been called!" << std::endl;
	*this = obj;
}

Ice& Ice::operator= (const Ice& obj)
{
	std::cout << "Ice assignment constructor has been called!" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor has been called!" << std::endl;
}

AMateria* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}