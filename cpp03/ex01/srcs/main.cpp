#include "ScavTrap.hpp"

int	main()
{
	ScavTrap bob;

	bob.attack("banane");
	bob.takeDamage(150);
	bob.attack("banane");
	bob.guardGate();
	return (0);
}