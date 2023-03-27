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
			std::cout << "Error\nToo many arguments" << std::endl;
		if (ac < 2)
			std::cout << "Error\nToo few arguments" << std::endl;
		return 0;
	}
	i = 0;
	while(av[1][i])
	{
		if (av[1][i] == ' ')
			++i;
		else if (isdigit(av[1][i]))
		{
			++values;
			pile.push(av[1][i] - 48);
			++i;
		}
		else if (isOperand(av[1][i]))
		{
			++operands;
			ApplyOperand(pile, av[1][i], &operands);
			++i;
		}
		else
		{
			std::cout << "Error\nRPN is incorrect" << std::endl;
			return (0);
		}
	}
	if (operands == values - 1)	
		std::cout << pile.top() << std::endl;
	else
		std::cout << "Error\nRPN is incorrect" << std::endl;
	return 0;
}
