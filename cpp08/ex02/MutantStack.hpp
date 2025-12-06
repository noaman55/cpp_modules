#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>


template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(): std::stack<T>() {}
		MutantStack(const MutantStack& copy): std::stack<T>(copy) {}

		MutantStack& operator= (const MutantStack& copy)
		{
			if (this != &copy)
				std::stack<T>::operator=(copy);
			return *this;
		}
		~MutantStack() {}
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
		const_iterator cbegin() {return this->c.cbegin();}
		const_iterator cend() {return this->c.cend();}

		reverse_iterator rbegin() {return this->c.rbegin();}
		reverse_iterator rend() {return this->c.rend();}
		const_reverse_iterator crbegin() {return this->c.crbegin();}
		const_reverse_iterator crend() {return this->c.crend();}
};

#endif
