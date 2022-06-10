#include "FragTrap.hpp"

FragTrap::FragTrap(void):_name("A FragTrap"), _HitPoints(100), _EnergyPoints(50), _AttackDamage(30)
{
	std::cout << this->_name << " has been constructed. Hyperion thank you for you purchase." << std::endl;
}

FragTrap::FragTrap(std::string name):_name(name), _HitPoints(100), _EnergyPoints(50), _AttackDamage(30)
{
	std::cout << this->_name << " has been constructed. Hyperion thank you for you purchase." << std::endl;
}

FragTrap::FragTrap(FragTrap const & father):_name(father._name), _HitPoints(father._HitPoints), _EnergyPoints(father._EnergyPoints), _AttackDamage(father._AttackDamage)
{
	std::cout << this->_name << " has been constructed. Hyperion thank you for you purchase." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << this->_name << " has been destructed. Hyperion also hates those annoying door keepers." << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &rhs)
{
	this->_name = rhs._name;
	this->_HitPoints = rhs._HitPoints;
	this->_EnergyPoints = rhs._EnergyPoints;
	this->_AttackDamage = rhs._AttackDamage;
	return (*this);
}

void	FragTrap::attack(std::string const & target)
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
	std::cout << _name << " threw a grenade at " << target << ", dealing " << _AttackDamage << " damages." << std::endl;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << _name << ": HIGH FIIIIIIIIIIIVE :D guys ? Where are you ? GUYS ?" << std::endl;
}