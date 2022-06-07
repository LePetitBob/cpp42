#include "zombie.hpp"

Zombie::Zombie(std::string name):_name(name)
{
	std::cout << name << " has risen from the dead !" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " went back to the grave." << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}