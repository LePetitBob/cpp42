#include "Harl.hpp"

int main(void)
{
	Harl  karen;
	std::string LevelOfAnnoyance;

	std::cin >> LevelOfAnnoyance;
	while (LevelOfAnnoyance != "LEAVING")
	{
		if (std::cin.eof() == true)
			break;
		karen.complain(LevelOfAnnoyance);
		std::cin >> LevelOfAnnoyance;
	}
	return (0);
}