#include "humanb.hpp"

HumanB::HumanB(std::string name):_name(name)
{
	_type = NULL;
	std::cout << "HumanB " << _name << " has been born" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << _name << " has been killed" << std::endl;
}

void	HumanB::attack(void) const
{
	std::cout << _name << " attack with their " << _type->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon & weapon)
{
	_type = &weapon;
}