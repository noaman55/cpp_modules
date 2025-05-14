#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
protected:
	std::string type;
public:
    Animal();
	Animal(const Animal& copy);
	Animal& operator= (const Animal& obj);
    virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const;
	virtual Brain* getBrain() = 0;
};



#endif