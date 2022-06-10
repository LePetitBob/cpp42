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

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

int		Fixed::operator>(const Fixed &rhs) const
{
	return ((this->toFloat() > rhs.toFloat()) ? 1: 0);
}

int		Fixed::operator<(const Fixed &rhs) const
{
	return ((this->toFloat() < rhs.toFloat()) ? 1: 0);
}

int		Fixed::operator>=(const Fixed &rhs) const
{
	return ((this->toFloat() >= rhs.toFloat()) ? 1: 0);
}

int		Fixed::operator<=(const Fixed &rhs) const
{
	return ((this->toFloat() <= rhs.toFloat()) ? 1: 0);
}

int		Fixed::operator==(const Fixed &rhs) const
{
	return ((this->toFloat() == rhs.toFloat()) ? 1: 0);
}

int		Fixed::operator!=(const Fixed &rhs) const
{
	return ((this->toFloat() != rhs.toFloat()) ? 1: 0);
}
Fixed	&Fixed::operator++(void)
{
	++(_rawBits);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	--(_rawBits);
	return (*this);
}
Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++(*this);
	return(tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--(*this);
	return(tmp);
}

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a: b);
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a: b);
}

Fixed const & Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a._rawBits > b._rawBits ? a: b);
}

Fixed const & Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a._rawBits < b._rawBits ? a: b);
}

std::ostream &  operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

