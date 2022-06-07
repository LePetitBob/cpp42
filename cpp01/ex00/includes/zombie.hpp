#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>

class Zombie{
	public :
		void announce(void);
		Zombie(std::string name);
		~Zombie();
	private :
		std::string	_name;
};

Zombie*	NewZombie(std::string name);
void	RandomChump(std::string name);

#endif