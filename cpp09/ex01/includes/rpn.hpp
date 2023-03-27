#ifndef RPN_HPP
# define RPN_HPP
# include <iomanip>
# include <iostream>
# include <stack>
# include <stdlib.h>

int		isOperand(char c);
void	ApplyOperand(std::stack<int> & pile, char o, int *operand);

#endif