#include "Animal.hpp"

Animal::Animal(): type("Unknown")
{
    std::cout << "Animal default constructor has been called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
    std::cout << "Animal copy constructor has been called" << std::endl;
    type = copy.type;
}

Animal& Animal::operator= (const Animal& obj)
{
	std::cout << "Animal assignment operator has been called" << std::endl;
	if (this != &obj)
	{
		type = obj.type;
	}
	return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor has been called" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound is Unknown" << std::endl;
}

Brain* Animal::getBrain()
{
    std::cout << "No brain for an unknown animal" << std::endl;
    return NULL;
}