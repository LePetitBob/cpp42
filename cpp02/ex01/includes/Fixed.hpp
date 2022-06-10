#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	public :

		Fixed();
		Fixed(const Fixed& fix);
		Fixed(const int rawBits);
		Fixed(const float rawBits);
		~Fixed();
		Fixed&	operator=(const Fixed &rhs);
		int		getrawBits(void) const;
		void	setrawBits(const int raw);
		int		toInt(void) const;
		float	toFloat(void) const;
		Fixed&	operator=(const Fixed &rhs);
	private :

		int					_rawBits;
		static const int	_BitsNbr = 8;
};

std::ostream &  operator<<(std::ostream & o, Fixed const & rhs);

#endif