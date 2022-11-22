#include "Litteral.hpp"

int main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cout << "wir haben eine problem" << std::endl;
		return (1);
	}

	Value val;
	val.setStr(av[1]);
	val.detectType();
	val.convert();
	val.display();

	return (0);
}