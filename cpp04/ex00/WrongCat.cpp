#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor has been called" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal()
{
    std::cout << "WrongCat copy constructor has been called" << std::endl;
    type = copy.type;
}

WrongCat& WrongCat::operator= (const WrongCat& obj)
{
	std::cout << "WrongCat assignment operator has been called" << std::endl;
	if (this != &obj)
	{
		type = obj.type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor has been called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "The Wrongcat is meowing" << std::endl;
}