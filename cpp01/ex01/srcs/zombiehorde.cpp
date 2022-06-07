#include "zombie.hpp"

Zombie	*ZombieHorde(int N, std::string name)
{
	Zombie	*first;

	first = new Zombie[N];
	for (int i = 0; i < N; i++)
		first[i].Set_name(name);
	return (first);
}
