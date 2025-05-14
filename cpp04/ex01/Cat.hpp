#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *ptr;
public:
    Cat();
    Cat(const Cat& copy);
	Cat& operator= (const Cat& obj);
    ~Cat();

    void makeSound() const;
    Brain* getBrain();
};



#endif