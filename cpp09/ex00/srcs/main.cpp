#include "btc.hpp"

int main(int ac, char **av)
{ 

	std::string					line;
	std::fstream				data;
	std::fstream				infile;
	std::map<std::string, float>	rate;

	if (ac != 2)
	{
		std::cout << "Error\nArguments are incorrect" << std::endl;
		return (1);
	}
	data.open("data.csv", std::ios::in);
	if (!data.is_open())
	{ 
		std::cout << "Error\nCouldn't open data file" << std::endl;
		return (1);
	}
	else
	{
		getline(data, line);
		while (getline(data, line))
			setData(rate, line);
		data.close();
	}
	for (int i = 1; i < ac; i++)
	{
		infile.open(av[1], std::ios::in);
		if (!infile.is_open())
		{
			std::cout << "Error\nCouldn't open input file" << std::endl;
			return (1);
		}
		else
		{
			while (getline(infile, line))
			{
				if (line.compare("date | value") != 0)
				{
					if (line.substr(0, line.find(' ')).compare(rate.begin()->first) < 0)
						std::cout << "Error : Date incorrect (" << line.substr(0, 10) << ")" << std::endl;
					else
						getData(rate, line);
				}
			}
			infile.close();
		}
	}

	return 0;
}
