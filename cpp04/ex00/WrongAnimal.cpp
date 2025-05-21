#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Unknown")
{
    std::cout << "WrongAnimal default constructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
    std::cout << "WrongAnimal copy constructor has been called" << std::endl;
    type = copy.type;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& obj)
{
	std::cout << "WrongAnimal assignment operator has been called" << std::endl;
	if (this != &obj)
	{
		type = obj.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor has been called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound is Unknown" << std::endl;
}