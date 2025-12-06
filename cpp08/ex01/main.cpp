#include "Span.hpp"
#include <iostream>
#include <algorithm>

int main()
{
	try
	{
		Span sp = Span(20000);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		// sp.genNumbers(20000);
		std::cout << "Shortest Span is: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span is: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}
