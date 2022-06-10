#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class Animal
{
	protected :
		std::string _type;
	public:
		Animal(void);
		Animal(Animal const & parent);
		Animal& operator=(Animal const & rhs);
		virtual ~Animal();
		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif