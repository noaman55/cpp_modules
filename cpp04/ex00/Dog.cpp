#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor has been called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog& copy): Animal()
{
    std::cout << "Dog copy constructor has been called" << std::endl;
    type = copy.type;
}

Dog& Dog::operator= (const Dog& obj)
{
	std::cout << "Dog assignment operator has been called" << std::endl;
	if (this != &obj)
	{
		type = obj.type;
	}
	return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor has been called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "The Dog is barking" << std::endl;
}