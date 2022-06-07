#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	Fixed d;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	c.setRawBits(42);
	d = c;
	std::cout << c.getRawBits() << std::endl;
	std::cout << d.getRawBits() << std::endl;
	return 0;
}