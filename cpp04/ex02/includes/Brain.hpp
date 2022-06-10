#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# include <iostream>

class Brain
{
	private :
		std::string _ideas[100];
	public:
		Brain(void);
		Brain(Brain const & parent);
		Brain& 			operator=(Brain const & rhs);
		~Brain();
		void			makeSound(void) const;
		std::string		getIdea(int i) const;
		void			setIdea(std::string idea, int i);
};

#endif