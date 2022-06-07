#include "sed.hpp"

int	error_rights()
{
	std::cout << "Access denied. Can't read or create file." << std::endl;
	return (1);
}

int	sed_is_for_losers(char **av)
{
	std::fstream	infile, outfile;
	std::string		input, buff, av2, av3;
	size_t			lastpos = 0;

	av2 = av[2];
	av3 = av[3];
	infile.open(av[1], std::ios::in);
	if (infile.fail())
		return (error_rights());
	outfile.open((std::string(av[1]) + ".replace").c_str(), std::ios::out);
	if (outfile.fail())
	{
		infile.close();
		return (error_rights());
	}
	while (std::getline(infile, input))
	{
		while ((lastpos = input.find(av2, lastpos)) != std::string::npos)
		{
			input.erase(lastpos, av2.size());
			input.insert(lastpos, av3);
			lastpos += av3.size();
		}
		outfile << input;
		if (!infile.eof())
			outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}	