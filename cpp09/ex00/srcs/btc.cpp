#include "btc.hpp"

int lineFormat(std::string line)
{
	int i = -1, year, month, day;
	std::string sample;
	if (line.size() < 14 || line.at(4) != '-' || line.at(7) != '-' || line.substr(10, 3).compare(" | "))
	{
		std::cout << "Error : Input file format is incorrect (" << line << ")" << std::endl;
		return (0);
	}
	sample = line.substr(0, 4);
	while (++i < 4)
		if (!isdigit(sample.at(i)))
	{
		std::cout << "Error : Input file format is incorrect (" << line << ")" << std::endl;
		return (0);
	}
	year = atoi(sample.c_str());
	if (!isdigit(line.at(5)) || !isdigit(line.at(6)))
	{
		std::cout << "Error : Input file format is incorrect (" << line << ")" << std::endl;
		return (0);
	}
	month = 10 * (line.at(5) - 48) + (line.at(6) - 48);
	if (!isdigit(line.at(8)) || !isdigit(line.at(9)))
	{
		std::cout << "Error : Input file format is incorrect (" << line << ")" << std::endl;
		return (0);
	}
	day = 10 * (line.at(8) - 48) + (line.at(9) - 48);
	if (month < 0 || month > 12 || day < 1 || day > 31)
	{
		std::cout << "Error : Date incorrect" << std::endl;
		return (0);
	}
	std::string date = line.substr(0, 10);
	std::string val_str = line.substr(13, line.size());
	float val = strtof(val_str.c_str(), NULL);
	if (val < 0 || val > 1000)
	{
		std::cout << "Error : Value of devise incorrect (" << val_str << ")" << std::endl;
		return (0);
	}
	return (1);
}

void setData(std::map<std::string, float> &rate, std::string line)
{
	std::string date = line.substr(0, line.find(','));
	std::string val_str = line.substr(line.find(',') + 1, line.size() - line.find(',') - 1).c_str();
	std::pair<std::string, float> paired = std::make_pair(date, strtof(val_str.c_str(), NULL));
	rate.insert(paired);
}

void getData(std::map<std::string, float> rate, std::string line)
{
	if (!lineFormat(line))
		return ;
	std::string date = line.substr(0, line.find('|') - 1);
	float value = strtof(line.substr(13, line.size()).c_str(), NULL);
	for (std::map<std::string, float>::iterator it = rate.begin(); it != rate.end(); it++)
	{
		if ((it->first).compare(date) == 0)
		{
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
			return ;
		}
		else if (it->first.compare(date) > 0)
		{
			if (rate.size() > 1)
				--it;
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
			return ;
		}
	}
	std::map<std::string, float>::iterator it = rate.end();
	--it;
	std::cout << date << " => " << value << " = " << it->second * value << std::endl;
}