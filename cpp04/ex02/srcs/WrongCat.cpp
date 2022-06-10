#include "WrongCat.hpp"

WrongCat::WrongCat(void):_type("WrongCat")
{
	std::cout << "Default constructor of WrongCat called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & parent):_type(parent._type)
{
	std::cout << "Copy constructor of WrongCat called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor of WrongCat called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "*glitching noise of incomplete creation*" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const & rhs)
{
	this->_type = rhs._type;
	return (*this);
}