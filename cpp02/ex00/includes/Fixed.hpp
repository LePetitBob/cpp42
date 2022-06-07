#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public :

		Fixed();
		Fixed(const Fixed& fix);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed&	operator=(const Fixed &fix);
	private :

		int					_rawBits;
		static const int	_BitsNbr = 8;
};

#endif