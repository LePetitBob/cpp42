#include "Fixed.hpp"

Fixed::Fixed(void): _rawBits(0)
{
	std::cout << "Default constructor has been called" << std::endl;
}

Fixed::Fixed(const Fixed& fix): _rawBits(fix._rawBits)
{
	std::cout << "Copy constructor has been called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

Fixed&	Fixed::operator=(const Fixed &fix)
{
	_rawBits = fix.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor has been called" << std::endl;
}