#ifndef BTC_HPP
# define BTC_HPP
# include <iomanip>
# include <iostream>
# include <string>
# include <sstream>
# include <fstream>
# include <cstring>
# include <cstdlib>
# include <stdio.h>
# include <unistd.h>
# include <utility>
# include <map>

void	setData(std::map<std::string, float> &rate, std::string line);
void	getData(std::map<std::string, float> rate, std::string line);
int 	lineFormat(std::string line);

#endif