#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "A wild karen appeared in the store !" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Finally ! Karen left the store !" << std::endl;
}

void	Harl::debug()
{
	std::cout << "Debug level :\n\"-I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::info()
{
	std::cout << "Info level :\n\"-I cannot believe adding extra bacon costs more money. You didn't putenough bacon in my burger! If you did, I wouldn't be asking for more !" << std::endl;
}

void	Harl::warning()
{
	std::cout << "Warning level :\n\"-I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "Error level :\n\"-This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG","INFO","WARNING","ERROR"} ;
	insistance ofcomplaints[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;

	while (i < 4 && level != levels[i])
		i++;
	if (i < 4)
		(this->*(ofcomplaints[i]))();
}