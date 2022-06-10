#include "Cat.hpp"

Cat::Cat(void):_type("Cat")
{
	std::cout << "Default constructor of cat called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(Cat const & parent):_type(parent._type)
{
	std::cout << "Copy constructor of cat called" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Destructor of cat called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "ich ni san Nyaaaaa arigatoooooooo" << std::endl;
}

Cat& Cat::operator=(Cat const & rhs)
{
	this->_type = rhs._type;
	return (*this);
}