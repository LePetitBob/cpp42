#include "span.hpp"

int main( void )
{
	srand(time(NULL));
	try{
		span test(4);
		span test2;
		span test3;
		// std::cout << test2.getSize() << std::endl;

		test.addNumber(10);
		std::cout << test.getSize() << std::endl;
		test.addNumber(15);
		std::cout << test.getSize() << std::endl;
		test.addNumber(20);
		std::cout << test.getSize() << std::endl;
		test.addNumber(50);
		std::cout << test.getSize() << "\n" << std::endl;
		
		test3 = test;
		test.printSpan();
		std::cout << std::endl;
		test3.printSpan();
		std::cout << "longest span : " << test.longestSpan() << "\nshortest span : " << test.shortestSpan() << std::endl;
		std::cout << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
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

	// try{
	// 	span test(25000);
	// 	test.fill();
	// 	std::cout << test.longestSpan() << " " << test.shortestSpan() << std::endl;
	// }
	// catch(std::exception &e){
	// 	std::cout << e.what() << std::endl;
	// }
	return 0;
}
