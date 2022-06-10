#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
	private :
		std::string _type;
	public:
		Dog(void);
		Dog(Dog const & parent);
		Dog& operator=(Dog const & rhs);
		virtual ~Dog();
		void	makeSound(void) const;
};

#endif