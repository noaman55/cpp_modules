#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <deque>
#include <time.h>

#define VECTOR 0
#define DEQUE 1

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
	PmergeMe(const PmergeMe& othter);
	PmergeMe& operator= (const PmergeMe& other);
	~PmergeMe();
	// void	parse_args(std::string& s);
	void	parse_args(char** args);
	void	binary_insertion(int container_flag, int val, int start, int end);
	int		binary_search(int container_flag, int val, int low, int high);
	void	sort_vect();
	void	sort_deque();
	void	print_list(std::string str, int flag);
};




#endif