#include "rpn.hpp"



int	isOperand(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}

void	ApplyOperand(std::stack<int> & pile, char o, int *operand)
{
	if (pile.size() <= 1)
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
			std::cout << "Error\nRPN is incorrect" << std::endl;
			exit(1);
		}
	}
	if (pile.size() < 2)
		return ;
	int tmp = pile.top();
	pile.pop();
	int tmp2 = pile.top();
	pile.pop();
	if (o == '+')
		pile.push(tmp + tmp2);
	else if (o == '-')
		pile.push(tmp2 - tmp);
	else if (o == '*')
		pile.push(tmp * tmp2);
	else if (o == '/')
		pile.push(tmp2 / tmp);
	return ;
}