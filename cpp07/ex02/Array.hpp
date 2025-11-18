#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
    T* tab;
    size_t length;
public:
    Array();
    Array(unsigned int n);
    Array(const Array& copy);
    Array& operator= (const Array& obj);
    ~Array();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t size() const;
};

#include "Array.tpp"

#endif