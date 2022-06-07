#include "zombie.hpp"

Zombie*	NewZombie(std::string name)
{
	Zombie *new_zombie = new Zombie(name);
	return (new_zombie);
}
