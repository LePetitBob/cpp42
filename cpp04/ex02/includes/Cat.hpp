#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private :
		std::string _type;
		Brain 		*_brain;
	public:
		Cat(void);
		Cat(Cat const & parent);
		Cat& operator=(Cat const & rhs);
		virtual ~Cat();
		void	makeSound(void) const;
		std::string		getIdea(int i) const;
};

#endif