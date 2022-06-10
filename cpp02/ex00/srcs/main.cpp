#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	Fixed d;

	c = b;
	std::cout << a.getrawBits() << std::endl;
	std::cout << b.getrawBits() << std::endl;
	std::cout << c.getrawBits() << std::endl;
	c.setrawBits(42);
	d = c;
	std::cout << c.getrawBits() << std::endl;
	std::cout << d.getrawBits() << std::endl;
	return 0;
}