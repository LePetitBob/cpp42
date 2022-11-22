#include "Identify.hpp"

int main(void)
{
	srand(time(NULL));
	std::cout << "generating 5 random classes :\n" << std::endl;
	Base *rndm1 = generate();
	Base *rndm2 = generate();
	Base *rndm3 = generate();
	Base *rndm4 = generate();
	Base *rndm5 = generate();

	std::cout << "\n\n identification with pointers :\n" << std::endl;
	identify(rndm1);
	identify(rndm2);
	identify(rndm3);
	identify(rndm4);
	identify(rndm5);

	std::cout << "\n\n identification with references :\n" << std::endl;
	identify(*rndm1);
	identify(*rndm2);
	identify(*rndm3);
	identify(*rndm4);
	identify(*rndm5);

	delete rndm1;
	delete rndm2;
	delete rndm3;
	delete rndm4;
	delete rndm5;
	return (0);
}
