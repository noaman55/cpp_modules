#ifndef MUTANTSTANCK_HPP
#define MUTANTSTANCK_HPP

#include <stack>

// template <typename T>

// class MutantStack : public std::stack<T>
// {
// private:
   
// public:
//     MutantStack () {};
//     ~MutantStack () {};
//     class iterator
//     {
//         private:
//         T* it;

//         public:
//         T* operator++()
//         {

//         }
//     };

//     iterator begin() {c.begin()};
//     iterator cbegin() {c.cbegin()};
//     iterator end() {c.end()};
//     iterator cend() {c.cend()};
//     iterator rbegin() {c.rbegin()};
//     iterator crbegin() {c.crbegin()};
//     iterator rend() {c.rend()};
//     iterator crend() {c.crernd()};
// };

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
    public:
    typedef Container container_type;
    typedef typename std::stack<T, Container>::container_type::iterator iterator;
    typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;

    public:
    iterator begin(){return this->c.begin();};
    iterator end(){return this->c.end();};
    const_iterator cbegin(){return this->c.cbegin();};
    const_iterator cend(){return this->c.cend();};

    reverse_iterator rbegin(){return this->c.rbegin();};
    reverse_iterator rend(){return this->c.rend();};
    const_reverse_iterator crbegin(){return this->c.crbegin();};
    const_reverse_iterator crend(){return this->c.crend();};
};
#endif