#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iomanip>
# include <iostream>
# include <exception>
# include <list>
# include <vector>
# include <map>
# include <algorithm>
 
template <typename T>
void		easyfind(T v, int n)
{
	typename T::iterator it;
	it = std::find(v.begin(), v.end(), n);
	if (it != v.end())
	{
		std::cout << "\n\nOcurrence found !\n" << std::endl;
		return ;
	}
	std::cout << "\n\nNo ocurrence found.\n" << std::endl;
	return ;
}

#endif