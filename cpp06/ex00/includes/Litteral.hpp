#ifndef LITTERAL_HPP
# define LITTERAL_HPP
#include <string>
#include <climits>
#include <cstdlib>
#include <iostream>

bool	IsInf(std::string input);
bool	IsDoubleOrFloat(std::string input);
bool	IsInt(std::string input);
bool	IsChar(std::string input);
void	CastChar(std::string input);
void	CastInt(std::string input);
void	Nan(void);

#endif