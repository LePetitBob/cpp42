#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	protected :
		std::string _type;
	public:
		WrongCat(void);
		WrongCat(WrongCat const & parent);
		WrongCat& operator=(WrongCat const & rhs);
		virtual ~WrongCat();
		void	makeSound(void) const;
};

#endif