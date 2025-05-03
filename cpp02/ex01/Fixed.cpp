#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	m_val = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
	m_val = val << frac_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val)
{
	m_val = (int)roundf(val * (1 << frac_bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	m_val = copy.m_val;
}

Fixed& Fixed::operator=(const Fixed& nbr)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	if (this == &nbr)
		return (*this);
	m_val = nbr.m_val;
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

float	Fixed::toFloat(void) const
{
	return static_cast <float> (m_val) / (1 << frac_bits);
}

int		Fixed::toInt(void) const
{
	return  m_val >> frac_bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& point)
{
	out << point.toFloat();
	return out;
}