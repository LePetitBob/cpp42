#include "span.hpp"

int main( void )
{
	try{
		span test(4);
		span test2;
		span test3;
		std::cout << test.getSize() << "\n" << std::endl;

		test.printSpan();
		std::cout << "\nadding values" << std::endl;
		test.addNumber(2);
		test.addNumber(10);
		test.addNumber(20);
		test.addNumber(50);
		// test.addNumber(51); // 5th value
		test.printSpan();
		std::cout << std::endl;
		
		test3 = test;
		test.printSpan();
		std::cout << "longest span : " << test.longestSpan() << "\nshortest span : " << test.shortestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << "\ntest 2 : size = 1, no comparison possible\n" << std::endl;
		span test(1);
		std::cout << test.getSize() << std::endl;
		std::cout << std::endl;
		std::cout << "longest span : " << test.longestSpan() << "\nshortest span : " << test.shortestSpan() << std::endl;
		std::cout << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << "\ntest 3 : size = 1, same, but testing shortest\n" << std::endl;
		span test(1);
		test.addNumber(42);
		std::cout << std::endl;
		std::cout << test.getSize() << std::endl;
		std::cout << std::endl;
		std::cout << "shortest span : " << test.shortestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n" << std::endl;

	try{
		std::cout << "\ntest 4 : size = 25 000, big boulot\n" << std::endl;
		span test(25000);
		std::cout << test.getSize() << std::endl;
		test.fill();
		// test.printSpan(); // This is dangerous... there are many elements !
		std::cout << test.longestSpan() << " " << test.shortestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}
