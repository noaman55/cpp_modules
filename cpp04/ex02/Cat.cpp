#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor has been called" << std::endl;
	type = "Cat";
	ptr = new Brain;
}

Cat::Cat(const Cat& copy): Animal()
{
	std::cout << "Cat copy constructor has been called" << std::endl;
	type = copy.type;
	ptr = new Brain;
	*ptr = *copy.ptr;
}

Cat& Cat::operator= (const Cat& obj)
{
	std::cout << "Cat assignment operator has been called" << std::endl;
	if (this != &obj)
	{
		type = obj.type;
		*ptr = *obj.ptr;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor has been called" << std::endl;
	delete ptr;
}

void Cat::makeSound() const
{
	std::cout << "The cat is meowing" << std::endl;
}

Brain* Cat::getBrain()
{
	return ptr;
}
