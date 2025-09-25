#include "Span.hpp"

Span::Span(/* args */)
{
}

Span::Span(unsigned int N): vecSize(0), vecCapacity(N)
{
    // vec.resize(N);
    // vec.clear();
    vec.reserve(N);
}

Span::~Span()
{
}

void Span::addNumber(int nbr)
{
    if (vecSize < vecCapacity)
    {
        vec.push_back(nbr);
        vecSize++;
    }
    else
        throw error("vec is full");
}

int Span::shortestSpan()
{
    int shortSpan;
    std::vector<int> arr = vec;

    if (vec.size() == 0 || vec.size() == 1)
        throw error("vector is empty or contain only one element");

    std::sort(arr.begin(), arr.end());
    std::vector<int>::iterator it = arr.begin();
    std::vector<int>::iterator next_it = ++arr.begin();

    // std::cout << *(++arr.begin()) << std::endl;
    // std::cout << *(arr.begin()) << std::endl;
    // return 42;
    shortSpan = *next_it - *it;
    while (next_it != arr.end() )
    {
        if (*next_it - *it < shortSpan)
            shortSpan = *next_it - *it;
        it = next_it++;
    }
    // while (it != arr.end() && next_it != arr.end() )
    // {
    //     if (*next_it - *it < shortSpan)
    //         shortSpan = *next_it - *it;
    //     it = next_it++;
    // }
    return shortSpan;
}

int Span::longestSpan()
{
    return (*std::max_element(vec.begin(), vec.end()) - *std::min_element(vec.begin(), vec.end()));
}