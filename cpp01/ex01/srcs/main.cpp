#include "zombie.hpp"

int	main(void)
{
	Zombie *first = ZombieHorde(4, "nullos");
	for (int i = 0; i < 4 ; i++)
		first[i].announce();
	delete[] first;
	return (0);
}