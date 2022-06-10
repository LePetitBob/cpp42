#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}

// int main( void )
// {
// 	const int i = 5;
// 	const float f = 42.42f;
// 	Fixed a;
// 	Fixed b( a );
// 	Fixed c( i );
// 	Fixed d( f );

// 	std::cout << a.getrawBits() << std::endl;
// 	std::cout << b.getrawBits() << std::endl;
// 	std::cout << c.toInt() << std::endl;
// 	std::cout << d.toFloat() << std::endl;
// 	c.setrawBits(42);
// 	d = c;
// 	std::cout << c.getrawBits() << std::endl;
// 	std::cout << d.getrawBits() << std::endl;
// 	return 0;
// }