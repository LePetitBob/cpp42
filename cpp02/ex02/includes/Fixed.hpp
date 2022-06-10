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
		int		getrawBits(void) const;
		void	setrawBits(const int raw);
		int		toInt(void) const;
		float	toFloat(void) const;
		Fixed&	operator=(const Fixed &rhs);
		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);
		static Fixed&	min(Fixed &a, Fixed &b);
		static Fixed&	max(Fixed &a, Fixed &b);
		static Fixed const &	min(Fixed const &a, Fixed const &b);
		static Fixed const &	max(Fixed const &a, Fixed const &b);
		int		operator>(const Fixed &rhs) const;
		int		operator<(const Fixed &rhs) const;
		int		operator<=(const Fixed &rhs) const;
		int		operator>=(const Fixed &rhs) const;
		int		operator==(const Fixed &rhs) const;
		int		operator!=(const Fixed &rhs) const;
	private :

		int					_rawBits;
		static const int	_BitsNbr = 8;
};

std::ostream &  operator<<(std::ostream & o, Fixed const & rhs);

#endif