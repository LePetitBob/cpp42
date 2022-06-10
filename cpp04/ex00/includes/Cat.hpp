#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{
	private :
		std::string _type;
	public:
		Cat(void);
		Cat(Cat const & parent);
		Cat& operator=(Cat const & rhs);
		virtual ~Cat();
		void	makeSound(void) const;
};

#endif