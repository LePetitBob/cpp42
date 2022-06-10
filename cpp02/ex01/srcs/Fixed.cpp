#include "Fixed.hpp"

Fixed::Fixed(void): _rawBits(0)
{
	std::cout << "Default constructor has been called" << std::endl;
}

Fixed::Fixed(const Fixed& fix): _rawBits(fix._rawBits)
{
	std::cout << "Copy constructor has been called" << std::endl;
}

Fixed::Fixed(const int rawBits)
{
	_rawBits = rawBits << _BitsNbr;
	// std::cout << " TMP -----> " << tmp << std::endl;
	std::cout << "Int constructor has been called" << std::endl;
}

Fixed::Fixed(const float rawBits)
{
	_rawBits = roundf(rawBits * (1 << _BitsNbr));
	std::cout << "Float constructor has been called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor has been called" << std::endl;
}

int	Fixed::toInt(void) const
{
	return (_rawBits >> _BitsNbr);
}

float Fixed::toFloat(void) const
{
	return ((float)_rawBits / (float)(1 << _BitsNbr));
}

int Fixed::getrawBits(void) const
{
	return (_rawBits);
}

void	Fixed::setrawBits(int const raw)
{
	_rawBits = raw;
}

Fixed&	Fixed::operator=(const Fixed &rhs)
{
	_rawBits = rhs.getrawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

std::ostream &  operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

