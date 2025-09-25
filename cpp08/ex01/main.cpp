#include "Span.hpp"

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(27);

// std::cout << sp.vec.size() << std::endl;
// std::cout << sp.vec.capacity() << std::endl;
for (size_t i = 0; i <  sp.vec.size(); i++)
    std::cout << sp.vec[i] << std::endl;

// return 0;
std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
std::cout << "shortestSpan: "<< sp.shortestSpan() << std::endl;
return 0;
}