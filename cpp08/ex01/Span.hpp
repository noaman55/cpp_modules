#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <string>



class error: public std::exception
{
	private:
		std::string str;
	public:
		error(std::string err): str(err){}
		~error() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {}
		virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {return str.c_str();}
};


class Span
{
private:
	std::vector<int> v;
	
public:
	Span(unsigned int);
	Span(const Span& other);
	Span& operator= (const Span& other);
	~Span();

	void	addNumber(int);
	int		shortestSpan();
	int		longestSpan();
	void	genNumbers(size_t element_nbs);
};

#endif
