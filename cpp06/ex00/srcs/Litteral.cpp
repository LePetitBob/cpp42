#include "Litteral.hpp"

long	GetValue(std::string input)
{
	const char *str = input.c_str();
	if (input.size() == 1 && ((str[0] > 31 && str[0] < 48) || (str[0] > 58 && str[0] < 126)))
		return (str[0]);
	return (std::atol(str));
}

bool	digitsOnly(std::string input)
{
	const char *str = input.c_str();
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i])
	{
		if (!std::isdigit(str[i]) && str[i] != '.')
			return (false);
		++i;
	}
	return (true);
}

bool	IsDoubleOrFloat(std::string input)
{
	const char	*str = input.c_str();
	int 		i = 0, j = 0;
	std::string	integer, fractional;

	if (str[i] == '-' || str[i] == '+')
		++i;
	while (std::isdigit(str[i]))
		++i;
	if (str[i] == '.')
	{
		integer = input.substr(0, i);
		++i;
	}
	else
		return (false);
	j = i;
	while (std::isdigit(str[i]))
		++i;
	if (!str[i] || (str[i] == 'f' && !str[i + 1]))
		fractional = input.substr(j, i - j);
	else
		return  (false);
	if (std::atoi(fractional.c_str()) == 0)
	{
		CastChar(integer);
		CastInt(integer);
	}
	else
	{
		std::cout << "char		:  impossible" << std::endl;
		std::cout << "int		:  impossible" << std::endl;
	}
	std::cout << "double 		:  " << std::atoi(integer.c_str()) << "." << fractional << std::endl;
	std::cout << "float		:  " << std::atoi(integer.c_str()) << "." << fractional << "f" << std::endl;
	return (true);
}

void	Nan(void)
{
	std::cout << "char			:  impossible" << std::endl;
	std::cout << "int			:  impossible" << std::endl;
	std::cout << "double			:  nan" << std::endl;
	std::cout << "float			:  nanf" << std::endl;
}

bool	IsInf(std::string input)
{
	std::string sign = "";
	if (input.at(0) == '-')
	{
		sign = "-";
		input.erase(0, 1);
	}
	if (!input.compare("inf") || !input.compare("inff"))
	{
		std::cout << "char			:  impossible" << std::endl;
		std::cout << "int			:  impossible" << std::endl;
		std::cout << "double			:  " << sign << "inf" << std::endl;
		std::cout << "float			:  " << sign << "inff" << std::endl;
		return (true);
	}
	return (false);
}

void	CastInt(std::string input)
{
	long	l = GetValue(input);
	int		i;
	
	if (l < INT_MIN || l > INT_MAX)
	{
		std::cout << "int		:  impossible" << std::endl;
		return ;
	} 
	i = l;
	std::cout << "int		:  " << i << std::endl;
	return ;
}

void	CastChar(std::string input)
{
	char	c;
	long	l;

	l = GetValue(input);
	if (l < 0 || l > 127)
	{
		std::cout << "char		:  impossible"  << std::endl;
		return ;
	}
	if ((l >= 0 && l < 32) || l == 127)
	{
		std::cout << "char		:  non displayable"  << std::endl;
		return ;
	}
	c = l;
	std::cout << "char		:  '" << c << "'" << std::endl;
	return ;
}

bool	IsChar(std::string input)
{
	const char *str = input.c_str();
	int i = 0;

	if (input.size() != 1)
		return (false);
	i = str[0];
	CastChar(input);
	CastInt(input);
	std::cout << "double 		:  " << i << ".0" << std::endl;
	std::cout << "float		:  " << i << ".0f" << std::endl;
	return (true);
}

bool	IsInt(std::string input)
{
	const char *str = input.c_str();
	int			i = 0, j = 0;
	std::string	integer;

	if (input.size() == 1 && !std::isdigit(str[0]))
		return (false);
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (std::isdigit(str[i]))
		++i;
	j = std::atoi(str);
	if (str[i] || j < INT_MIN || j > INT_MAX)
		return (false);
	CastChar(input);
	CastInt(input);
	std::cout << "double 		:  " << j << ".0" << std::endl;
	std::cout << "float		:  " << j << ".0f" << std::endl;
	return (true);
}
