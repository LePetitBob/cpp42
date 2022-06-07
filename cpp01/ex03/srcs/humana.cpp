#include "humana.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):_name(name), _type(weapon)
{
	std::cout << "HumanA " << _name << " has been born" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA " << _name << " has been killed" << std::endl;
}

void	HumanA::attack(void) const
{
	std::cout << "HumanA " << _name << " attacked with " << _type.getType() << std::endl;
}