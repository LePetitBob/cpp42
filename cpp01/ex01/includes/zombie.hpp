#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>
# include <string>

class Zombie{
	public :
		void announce(void);
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	Set_name(std::string name);
	private :
		std::string	_name;

};

Zombie*	ZombieHorde(int N, std::string name);

#endif