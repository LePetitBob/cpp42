#include "Animal.hpp"

Animal::Animal(void):_type("Animal")
{
	std::cout << "Default constructor of Animal called" << std::endl;
}

Animal::Animal(Animal const & parent):_type(parent._type)
{
	std::cout << "Copy constructor of Animal called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor of Animal called" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (_type);
}

Animal& Animal::operator=(Animal const & rhs)
{
	this->_type = rhs._type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Random animal noise" << std::endl;
}