#include "rpn.hpp"



int	isOperand(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}

void	ApplyOperand(std::stack<int> &pile, char o, int *operand)
{
	if (pile.size() < 2)
	{
		if (o == '-')
		{
			(*operand)--;
			int tmp = pile.top();
			pile.pop();
			pile.push(-tmp);
			return ;
		}
		else
		{
			std::cerr << "Error\nRPN is incorrect" << std::endl;
			exit(1);
		}
	}
	int b = pile.top();
	pile.pop();
	int a = pile.top();
	pile.pop();
	if (o == '+')
		pile.push(a + b);
	else if (o == '-')
		pile.push(a - b);
	else if (o == '*')
		pile.push(a * b);
	else if (o == '/')
	{
		if (b == 0)
		{
			std::cerr << "Error\nDivision by zero" << std::endl;
			exit(1);
		}
		pile.push(a / b);
	}
	return ;
}