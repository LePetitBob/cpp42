#include "weapon.hpp"

Weapon::Weapon(void)
{
	std::cout << "Weapon has been created" << std::endl;
}

Weapon::Weapon(std::string type):_type(type)
{
	std::cout << "A " << _type << " has been created" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon has been destroyed" << std::endl;
}

std::string	Weapon::getType(void) const
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}