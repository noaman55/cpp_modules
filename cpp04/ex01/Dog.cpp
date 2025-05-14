#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor has been called" << std::endl;
    type = "Dog";
    ptr = new Brain;
}

Dog::Dog(const Dog& copy): Animal()
{
    std::cout << "Dog copy constructor has been called" << std::endl;

    type = copy.type;
    ptr = new Brain;
    for (int i = 0; i < 100; i++)
    {
        ptr->setIdea(i , copy.ptr->getIdea(i));
    }
    // ptr = copy.ptr;
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

Brain* Dog::getBrain()
{
    return ptr;
}