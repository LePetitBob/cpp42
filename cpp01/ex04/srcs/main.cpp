#include "sed.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error : wrong parameters..." << std::endl;
		return (0);
	}
	return (sed_is_for_losers(av));
}