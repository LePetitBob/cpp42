#include "zombie.hpp"

void	RandomChump(std::string name)
{
	Zombie *chump = new Zombie(name);
	chump->announce();
	delete chump;
	return ;
}