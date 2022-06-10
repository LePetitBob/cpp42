#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void):_name("A ScavTrap"), _HitPoints(100), _EnergyPoints(50), _AttackDamage(20)
{
	std::cout << this->_name << " has been constructed. Hyperion thank you for you purchase." << std::endl;
}

ScavTrap::ScavTrap(std::string name):_name(name), _HitPoints(100), _EnergyPoints(50), _AttackDamage(20)
{
	std::cout << this->_name << " has been constructed. Hyperion thank you for you purchase." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & father):_name(father._name), _HitPoints(father._HitPoints), _EnergyPoints(father._EnergyPoints), _AttackDamage(father._AttackDamage)
{
	std::cout << this->_name << " has been constructed. Hyperion thank you for you purchase." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->_name << " has been destructed. Hyperion also hates those annoying door keepers." << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &rhs)
{
	this->_name = rhs._name;
	this->_HitPoints = rhs._HitPoints;
	this->_EnergyPoints = rhs._EnergyPoints;
	this->_AttackDamage = rhs._AttackDamage;
	return (*this);
}

void	ScavTrap::attack(std::string const & target)
{
	if (_EnergyPoints == 0)
	{
		std::cout << _name << " can't do anything without energy." << std::endl;
		return ;
	}
	--_EnergyPoints;
	if (_HitPoints == 0)
	{
		std::cout << _name << " can't  do anything while he's... well... dead as it can be." << std::endl;
		return ;
	}
	std::cout << _name << " rolls over " << target << ", dealing " << _AttackDamage << " damages." << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << _name << ": It's a VERY important duty to guard the main gate of the old communication facility." << std::endl;
}