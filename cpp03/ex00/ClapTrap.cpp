#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):_name("A Claptrap"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap " << _name << " has been constructed. Hyperion thank you for you purchase." << std::endl;
}

ClapTrap::ClapTrap(std::string name):_name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap " << _name << " has been constructed. Hyperion thank you for you purchase." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & father):_name(father._name), _HitPoints(father._HitPoints), _EnergyPoints(father._EnergyPoints), _AttackDamage(father._AttackDamage)
{
	std::cout << "ClapTrap " << _name << " has been constructed. Hyperion thank you for you purchase." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been destructed. Hyperion also hates those annoying door openers." << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &rhs)
{
	_name = rhs._name;
	_HitPoints = rhs._HitPoints;
	_EnergyPoints = rhs._EnergyPoints;
	_AttackDamage = rhs._AttackDamage;
	return (*this);
}

void	ClapTrap::attack(std::string const & target)
{
	if (_EnergyPoints == 0)
	{
		std::cout << _name << " can't do anything without energy." << std::endl;
		return ;
	}
	--_EnergyPoints;
	if (_HitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't  do anything while he's... well... dead as it can be." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", dealing " << _AttackDamage << " damages." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int ammount)
{
	if (_HitPoints == 0)
	{
		std::cout << "Man....  ClapTrap " << _name << "'s already broken to pieces..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " suffered " << ammount << " damages" << std::endl;
	if (_HitPoints - (int)ammount <= 0)
	{
		_HitPoints = 0;
		std::cout << "\"BWAAAAARGH...\"\nClapTrap " << _name << " died horribly and painfully in a long agony. " << std::endl;
		return ;
	}
	_HitPoints -= ammount;
}

void	ClapTrap::beRepaired(unsigned int ammount)
{
	if (_EnergyPoints == 0)
	{
		std::cout << _name << " can't do anything without energy." << std::endl;
		return ;
	}
	--_EnergyPoints;
	if (_HitPoints + ammount > 10)
		_HitPoints = 10;
	else
		_HitPoints += ammount;
	std::cout << "*BZZZZT BZZZZT CRANK CLONG (and other weird cartoony mechanical noises)*\nClapTrap " << _name << " recovered " << ammount << " hit points" << std::endl;
}

int	ClapTrap::getHitPoints(void)
{
	return (_HitPoints);
}