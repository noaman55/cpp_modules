#include "Brain.hpp"

Brain::Brain()
{
}
Brain::Brain(const Brain& src)
{
    *this = src;
}

Brain& Brain::operator=(const Brain& src)
{
    if (this != &src)
    {

    }
    return *this;
}

Brain::~Brain()
{
}

void Brain::setIdea(int index, std::string idea)
{
    ideas[index] = idea;
}

std::string Brain::getIdea(int index)
{
	return ideas[index];
}