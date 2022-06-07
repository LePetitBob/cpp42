#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "weapon.hpp"

class	HumanA
{
	public :
		HumanA(std::string name, Weapon &type);
		~HumanA();
		Weapon		&getType(void) const;
		void		attack(void) const;
	private :
		std::string	_name;
		Weapon&		_type;
};

#endif