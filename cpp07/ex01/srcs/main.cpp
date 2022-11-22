#include "iter.hpp"

int main( void )
{
	// Creating a int[5] array and filling it
	int a[5] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++)
		a[i] = i + 1;

	// Printing values
	for (int i = 0; i < 5; i++)
		std::cout << a[i] << std::endl;

	// Using iter, which apply a function to every element of the array
	iter(a, 5, &inc);
	std::cout	<< "\nnew values :" 
				<< std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << a[i] << std::endl;

//!---------------------------------------------------------------------

	std::cout	<< "\n" << std::endl;
	
	// Creating a char[6] array and filling it
	char b[6] = "abcde";

	// Printing values
	for (int i = 0; i < 6; i++)
		std::cout << b[i] << std::endl;

	// Using iter, which apply a function to every element of the array
	iter(b, 6, &inc);
	std::cout	<< "\nnew values :" 
				<< std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << b[i] << std::endl;
	return 0;
}
