#include "Litteral.hpp"

int main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cout << "wir haben eine problem" << std::endl;
		return (1);
	}
	std::string input = av[1];
	if (IsInf(input))
		return (0);
	else if (IsDoubleOrFloat(input))
		return (0);
	else if (IsInt(input))
		return (0);
	else if (IsChar(input))
		return (0);
	Nan();
	std::cout << "arbeit beendet" << std::endl;
	return (0);
}