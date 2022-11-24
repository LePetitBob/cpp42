#ifndef SPAN_HPP
# define SPAN_HPP
# include <iomanip>
# include <iostream>
# include <exception>
# include <time.h>
# include <list>
# include <vector>
# include <map>
# include <algorithm>
# include <cmath>
 
class span
{
	private :
		std::vector<int>	_v;
		unsigned int		_sizemax;

	public :
		span(void);
		span(int size);
		span(const span & parent);
		~span(void);
		void			addNumber(int n);
		int				longestSpan(void);
		int				shortestSpan(void);
        class NoMoreSpaceException : public std::exception
                {
            const char  *what(void) const throw();
        };
        class NotEnoughValuesException : public std::exception
                {
            const char	*what(void) const throw();
        };
		unsigned int	getSize(void);
		void			printSpan(void);
		void			fill(void);
};

#endif