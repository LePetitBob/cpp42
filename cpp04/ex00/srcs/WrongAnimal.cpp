#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void):_type("WrongAnimal")
{
	std::cout << "Default constructor of WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & parent):_type(parent._type)
{
	std::cout << "Copy constructor of WrongAnimal called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor of WrongAnimal called" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & rhs)
{
	this->_type = rhs._type;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Random WrongAnimal noise" << std::endl;
}