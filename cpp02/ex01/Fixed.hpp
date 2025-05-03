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
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& nbr);
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;

};

std::ostream& operator<<(std::ostream& out, const Fixed& point);

#endif