#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iomanip>
# include <iostream>
# include <exception>
# include <time.h>
# include <stack>
# include <list>
# include <algorithm>
# include <cmath>
 
template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack<T>(void) : std::stack<T>(){}
		MutantStack<T>(MutantStack const & parent) : std::stack<T>(parent) {}
		virtual ~MutantStack<T>(void) {}

		typedef typename std::stack< T >::container_type::iterator iterator;
		iterator begin()
		{
			return (std::stack< T >::c.begin());
		}

		iterator end()
		{
			return (std::stack< T >::c.end());
		}
		
		MutantStack<T> & operator=(MutantStack const & rhs)
		{
			std::stack<T>::operator=(rhs);
		}

	};

	#endif