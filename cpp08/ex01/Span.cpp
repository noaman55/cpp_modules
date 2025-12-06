#include "Span.hpp"
#include <algorithm>
#include <numeric>
#include <iostream>

Span::Span(unsigned int N)
{
	v.reserve(N);
}

Span::Span(const Span& other): v(other.v)
{

}

Span& Span::operator= (const Span& other)
{
	if (this != &other)
	{
		v = other.v;
	}
	return *this;
}

Span::~Span()
{

}

void	Span::addNumber(int n)
{
	if (v.size() < v.capacity())
		v.push_back(n);
	else
		throw error("Error: the vector is full, you can't add any number");
}
int	Span::shortestSpan()
{
	if (v.empty() || v.size() == 1)
		throw error("Error: empty vector or it contain one integer");

	std::vector<int> tmp(v);
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
	return *std::min_element(tmp.begin() + 1, tmp.end());
}

int	Span::longestSpan()
{
	if (v.empty() || v.size() == 1)
			throw error("Error: empty vector or it contain one integer");
	return *std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end());
}

void	Span::genNumbers(size_t element_nbs)
{
	if (element_nbs > v.capacity())
		throw error("Error: the number of elements to generate is greater than the container capacity");
	v.clear();
	srand(time(NULL));
	v.resize(element_nbs);
	std::generate_n(v.begin(), element_nbs, std::rand);
	// for (size_t i = 0; i < element_nbs; i++)
	// {
	// 	v.push_back(std::rand());
	// }
}
