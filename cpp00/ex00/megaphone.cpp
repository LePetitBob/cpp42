#include <iostream>
#include <iomanip>
#include <string>

void	print_upper(std::string s)
{
	size_t		i = 0;

	while (i < s.size())
	{
		s.at(i) = std::toupper(s.at(i));
		++i;
	}
	std::cout << s;
}

int	main(int ac, char **av)
{
	int	i = 0;

	if (ac < 2)
	{
		if (ac == 1)
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (++i < ac)
		print_upper(av[i]);
	std::cout << std::endl;
	return (0);
}