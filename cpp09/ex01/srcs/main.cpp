#include "rpn.hpp"

int main( int ac, char **av )
{
	std::stack<int>	pile;
	int				i;
	int				values = 0;
	int				operands = 0;

	if (ac != 2)
	{
		if (ac > 2)
			std::cerr << "Error\nToo many arguments" << std::endl;
		if (ac < 2)
			std::cerr << "Error\nToo few arguments" << std::endl;
		return 0;
	}
	i = 0;
	while(av[1][i])
	{
		if (isdigit(av[1][i]))
			++values;
		else if (isOperand(av[1][i]))
			++operands;
		else if (av[1][i] != ' ')
			return (std::cerr << "Error\nInvalid character" << std::endl, 1);
		++i;
	}
	if (operands != values - 1)	
		return (std::cerr << "Error\nRPN is incorrect" << std::endl, 1);
	i = 0;
	while(av[1][i])
	{
		if (isdigit(av[1][i]))
			pile.push(av[1][i] - 48);
		else if (isOperand(av[1][i]))
			ApplyOperand(pile, av[1][i], &operands);
		else if (av[1][i] != ' ')
		{
			std::cerr << "Error\nRPN is incorrect" << std::endl;
			return (0);
		}
		++i;
	}
	std::cout << pile.top() << std::endl;
	return 0;
}
