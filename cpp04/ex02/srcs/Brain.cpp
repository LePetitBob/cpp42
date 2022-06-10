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

std::string	Brain::getIdea(int i) const
{
	return _ideas[i];
}

void	Brain::setIdea(std::string idea, int i)
{
	_ideas[i] = idea;
}

Brain& Brain::operator=(Brain const & rhs)
{
	for (int i = 0 ; i < 100 ; i++)
		_ideas[i] = rhs._ideas[i];
	return (*this);
}