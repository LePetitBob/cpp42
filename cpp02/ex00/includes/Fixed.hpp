#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public :

		Fixed();
		Fixed(const Fixed& fix);
		~Fixed();
		int		getrawBits(void) const;
		void	setrawBits(int const raw);
		Fixed&	operator=(const Fixed &rhs);
	private :

		int					_rawBits;
		static const int	_BitsNbr = 8;
};

#endif