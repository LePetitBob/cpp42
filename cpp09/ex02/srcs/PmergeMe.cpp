#include "PmergeMe.hpp"

void	check_and_fill(int ac, char **av, std::vector<int> &v, std::deque<int> &d)
{
	for (int i = 1; i < ac; i++)
	{
		for (size_t j = 0; j < strlen(av[i]); j++)
		{
			if ((j == 0 && av[i][j] != '+' && !isdigit(av[i][j])) || !isdigit(av[i][j]))
			{
				std::cout << "Error\nInvalid arguments. Must be only positive integers" << std::endl;
				exit(1);
			}
		}
		long value = atol(av[i]);
		if (strlen(av[1]) > 11 || value < 0 || value > 2147483647)
		{
			std::cout << "Error\nOut of range. Must be only positive integers" << std::endl;
			exit(1);
		}
		v.push_back(atoi(av[i]));
		d.push_back(atoi(av[i]));
	}
}
