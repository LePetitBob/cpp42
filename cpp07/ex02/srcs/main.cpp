#include "Array.hpp"

int main( void )
{
	Array<char> a(5);
	for ( int i = 0; i < 5; i++)
		a[i] = i + 97;
	a.print();

	Array<int> b(5);
	for ( int i = 0; i < 5; i++)
		b[i] = i;
	b.print();
	
	std::cout << std::endl;
	Array<int> c(5);
	c = b;
	c[0] = c[0] + 10;
	b.print();
	std::cout << std::endl;
	c.print();
	
	std::cout << std::endl;
	Array<int> d(5);
	Array<int> e;
	d = c;
	e = d;
	d[0] = d[0] + 10;
	d.print();
	std::cout << std::endl;
	e.print();

	//Testing wrong index
	try{
		std::cout << b[7] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//Testing empty array
	Array<int> v;
	try{
		std::cout << v[7] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
