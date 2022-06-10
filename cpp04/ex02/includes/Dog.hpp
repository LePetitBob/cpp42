#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private :
		std::string _type;
		Brain 		*_brain;
	public:
		Dog(void);
		Dog(Dog const & parent);
		Dog& operator=(Dog const & rhs);
		virtual ~Dog();
		void	makeSound(void) const;
		std::string		getIdea(int i) const;
};

#endif