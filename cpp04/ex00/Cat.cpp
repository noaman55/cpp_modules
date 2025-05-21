#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor has been called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& copy): Animal()
{
    std::cout << "Cat copy constructor has been called" << std::endl;
    type = copy.type;
}

Cat& Cat::operator= (const Cat& obj)
{
	std::cout << "Cat assignment operator has been called" << std::endl;
	if (this != &obj)
	{
		type = obj.type;
	}
	return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor has been called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "The cat is meowing" << std::endl;
}