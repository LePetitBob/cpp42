#include "Dog.hpp"

Dog::Dog(void):_type("Dog")
{
	std::cout << "Default constructor of dog called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(Dog const & parent):_type(parent._type)
{
	std::cout << "Copy constructor of dog called" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Destructor of dog called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "bwouf :$p" << std::endl;
}

Dog& Dog::operator=(Dog const & rhs)
{
	this->_type = rhs._type;
	return (*this);
}