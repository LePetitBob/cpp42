#ifndef ClapTrap_HPP
# define ClapTrap_HPP
# include <iostream>
# include <string>

class ClapTrap
{
	private:
		std::string _name;
		int			_HitPoints;
		int			_EnergyPoints;
		int			_AttackDamage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & father);
		ClapTrap&	operator=(const ClapTrap &rhs);
		~ClapTrap(void);
		void	attack(std::string const & target);
		void	takeDamage(unsigned int ammount);
		void	beRepaired(unsigned int ammount);
		int		getHitPoints(void);
};

#endif
