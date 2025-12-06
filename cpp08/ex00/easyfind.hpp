#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <string>

class error:public std::exception
{
	public:
		error() {};
		virtual ~error() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{};
		virtual const char* what() const throw() {return "Number not found";};
};


template <typename T>
typename T::iterator	easyfind(T& container, int n);

// template <typename T>
// typename T::iterator	easyfind(T& container, int n)
// {
// 	typename T::iterator it = find(container.begin(), container.end(), n);

// 	if (it != container.end())
// 		return it;
// 	else
// 		throw error();
// }

#include "easyfind.tpp"
#endif

