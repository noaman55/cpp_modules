#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <deque>


class error: public std::exception
{
	private:
		std::string str;
	public:
		error(std::string err): str(err) {};
		~error() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {};
		virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {return str.c_str();};
};


class PmergeMe
{
private:
	std::vector<int>	vect;
	std::deque<int>		deque;
	int					struggle;
	public:
	PmergeMe();
	~PmergeMe();
	void	parse_args(std::string& s);
	void	sort_pairs();
	void	print_list();
};




#endif