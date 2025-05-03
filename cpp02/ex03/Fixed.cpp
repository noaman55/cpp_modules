#include "Fixed.hpp"
#include <cmath>

//////////////// Constructors and destructor ////////////////

Fixed::Fixed()
{
	m_val = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
	m_val = val << frac_bits;
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val)
{
	m_val = roundf(val * (1 << frac_bits));
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	m_val = copy.m_val;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	// std::cout << "Copy assignment constructor called" << std::endl;
	if (this == &copy)
		return (*this);
	m_val = copy.m_val;
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

//////////////// Member functions ////////////////

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

Fixed& Fixed::min(Fixed& a, Fixed&b)
{
	if (a > b)
		return b;
	return a;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return b;
	return a;
}

Fixed& Fixed::max(Fixed& a, Fixed&b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

//////////////// Comparaison operators overloading ////////////////

bool Fixed::operator>(const Fixed& point) const
{
	return this->m_val > point.m_val;
}

bool Fixed::operator<(const Fixed& point) const
{
	return  this->m_val < point.m_val;
}

bool Fixed::operator>=(const Fixed& point) const
{
	return this->m_val >= point.m_val;
}

bool Fixed::operator<=(const Fixed& point) const
{
	return this->m_val <= point.m_val;
}

bool Fixed::operator==(const Fixed& point) const
{
	return this->m_val == point.m_val;
}

bool Fixed::operator!=(const Fixed& point) const
{
	return this->m_val != point.m_val;
}

//////////////// Arithmetic operators overloading ////////////////

Fixed Fixed::operator+(const Fixed& point) const
{
	Fixed fixed_point;

	fixed_point.setRawBits(this->m_val + point.m_val) ;

	return fixed_point;
}

Fixed Fixed::operator-(const Fixed& point) const
{
	Fixed fixed_point;

	fixed_point.setRawBits(this->m_val - point.m_val) ;

	return fixed_point;
}

Fixed Fixed::operator*(const Fixed& point) const
{
	Fixed fixed_point;

	fixed_point.setRawBits(this->m_val * point.m_val >> frac_bits) ;

	return fixed_point;
}

Fixed Fixed::operator/(const Fixed& point) const
{
	Fixed fixed_point;

	fixed_point.setRawBits((float) this->m_val / point.m_val * (1 << frac_bits));

	return fixed_point;
}

//////////////// increment/decrement operators overloading ////////////////

Fixed Fixed::operator++(void)
{
	*this = *this +  Fixed(1.00f / (1 << frac_bits));

	return *this;
}

Fixed Fixed::operator--(void)
{
	*this = *this - Fixed(1.00f / (1 << frac_bits));

	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed point = *this;

	this->operator++();

	return point;
}

Fixed Fixed::operator--(int)
{
	Fixed point = *this;

	this->operator--();
	
	return point;
	
}
