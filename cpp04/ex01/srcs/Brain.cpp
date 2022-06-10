#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default constructor of brain called" << std::endl;
}

Brain::Brain(Brain const & parent)
{
	*this = parent;
	std::cout << "Copy constructor of brain called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destructor of brain called" << std::endl;
}

void	Brain::makeSound(void) const
{
	std::cout << "ich ni san Nyaaaaa arigatoooooooo" << std::endl;
}

Brain& Brain::operator=(Brain const & rhs)
{
	for (int i = 0 ; i < 100 ; i++)
		_ideas[i] = rhs._ideas[i];
	return (*this);
}