#include "zombie.hpp"

int	main(void)
{
	Zombie first("first");
	Zombie *second;
	first.announce();
	RandomChump("Bob");
	second = NewZombie("second");
	second->announce();
	delete second;
	return (0);
}