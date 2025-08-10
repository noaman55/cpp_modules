#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>

// class error: public std::exception
// {
//     public:
//     const char* what() const throw(){
//         return "vec is full";
//     }
// };

class error
{
    private:
    std::string msg;

    public:
    error(std::string error):msg(error){};
    std::string what() const throw(){
        return msg;
    }
};

class Span
{
public:
    std::vector<int> vec;
    unsigned int vecSize;
    unsigned int vecCapacity;
public:
    Span();
    Span(unsigned int N);
    ~Span();

    void addNumber(int nbr);
    int shortestSpan();
    int longestSpan();
};



#endif