#include "Fixed.hpp"

Fixed::Fixed()
{
    m_val = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    m_val = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& nbr)
{
    std::cout << "Copy assignment constructor called" << std::endl;
    if (this == &nbr)
        return (*this);
    m_val = nbr.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (m_val);
}

void Fixed::setRawBits( int const raw )
{
    m_val = raw;
}
