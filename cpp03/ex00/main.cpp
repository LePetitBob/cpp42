#include "ClapTrap.hpp"

int	main()
{
	ClapTrap first("bichon");

	first.attack("Brice");
	first.takeDamage(9);
	first.attack("Brice");
	first.takeDamage(22);
	first.takeDamage(54);
	first.attack("Brice");
	first.beRepaired(10);
	first.attack("Brice");
	return (0);
}