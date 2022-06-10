#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		std::string _name;
		int			_HitPoints;
		int			_EnergyPoints;
		int			_AttackDamage;
	public :
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const & father);
		~FragTrap();
		FragTrap&	operator=(const FragTrap &rhs);
		void	attack(std::string const & target);
		void	highFiveGuys(void);
};

#endif