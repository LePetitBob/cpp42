#include <iostream>
#include <string>

int	main(void)
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << &brain << "\n" << stringPTR << "\n" << &stringREF << " \n" << std::endl;

	std::cout << brain << "\n" << *stringPTR << "\n" << stringREF << " \n" << std::endl;

	return (0);
}