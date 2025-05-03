#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int m_val;
		static const int frac_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& nbr);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
#endif