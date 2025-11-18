#include "Array.hpp"
#include <cstddef>
#include <cstdlib>
#include <stdexcept>

template <typename T>
Array<T>::Array(): tab(NULL), length(0)
{

}

template <typename T>
Array<T>::Array(unsigned int n)
{
    try
    {
        tab = new T[n]();
        length = n;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit (1);
    }   
}

template <typename T>
Array<T>::Array(const Array& copy)
{
    try
    {
        tab = new T[copy.length];
        length = copy.length;
        for (size_t i = 0; i < length; i++)
            tab[i] = copy.tab[i];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit (1);
    } 
}

template <typename T>
Array<T>& Array<T>::operator= (const Array& obj)
{
    if (&obj != this)
    {
        try
        {
            delete[] tab;
            tab = new T[obj.length];
            length = obj.length;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            exit (1);
        }
        for (size_t i = 0; i < length; i++)
            tab[i] = obj.tab[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] tab;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
    if (index < length)
        return tab[index];
    else
        throw std::out_of_range("Out of range");
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index < length)
        return tab[index];
    else
        throw std::out_of_range("Out of range");
}

template <typename T>
size_t Array<T>::size() const
{
    return length;
}
