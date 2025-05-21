#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *ptr;
    
public:
    Dog();
    Dog(const Dog& copy);
	Dog& operator= (const Dog& obj);
    ~Dog();

    void makeSound() const;
    Brain* getBrain();
};



#endif