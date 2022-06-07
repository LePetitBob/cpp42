#ifndef KAREN_HPP
# define KAREN_HPP
# include <iostream>
# include <string>

class Harl
{
	public:

		Harl();
		~Harl();
		void	complain(std::string LevelOfAnnoyance);

	private:

		void	debug();
		void	info();
		void	warning();
		void	error();

};

typedef void (Harl::*insistance)(void);

#endif