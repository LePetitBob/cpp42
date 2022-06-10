#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		std::string _name;
		int			_HitPoints;
		int			_EnergyPoints;
		int			_AttackDamage;
	public :
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & father);
		~ScavTrap();
		ScavTrap&	operator=(const ScavTrap &rhs);
		void	attack(std::string const & target);
		void	guardGate(void);
};

#endif