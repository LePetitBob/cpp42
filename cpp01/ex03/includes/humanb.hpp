#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "weapon.hpp"

class	HumanB
{
	public :
		HumanB(std::string name);
		~HumanB();
		Weapon		&getType(void) const;
		void		setWeapon(Weapon & weapon);
		void		attack(void) const;
	private :
		std::string	_name;
		Weapon*		_type;
};

#endif