#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor has been called" << std::endl;
}
Brain::Brain(const Brain& src)
{
    std::cout << "Brain copy constructor has been called" << std::endl;
    *this = src;
}

Brain& Brain::operator=(const Brain& src)
{
    std::cout << "Brain assignment operator has been called" << std::endl;
    if (this != &src)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = src.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor has been called" << std::endl;
}

void Brain::setIdea(int index, std::string idea)
{
    if (index < 0 || index > 99)
    {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    ideas[index] = idea;
}

std::string Brain::getIdea(int index)
{
    if (index < 0 || index > 99)
    {
        std::cout << "Invalid index" << std::endl;
        return NULL;
    }
	return ideas[index];
}