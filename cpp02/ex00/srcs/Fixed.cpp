#include "Fixed.hpp"

Fixed::Fixed(void): _rawBits(0)
{
	std::cout << "Default constructor has been called" << std::endl;
}

Fixed::Fixed(const Fixed& fix): _rawBits(fix._rawBits)
{
	std::cout << "Copy constructor has been called" << std::endl;
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

Fixed::~Fixed(void)
{
	std::cout << "Destructor has been called" << std::endl;
}