#include "zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "a zombie has risen from the dead !" << std::endl;
	return ;
}


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

void	Zombie::Set_name(std::string name)
{
	_name = name;
}
