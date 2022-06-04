#include "phonebook.hpp"

int	main(void)
{
	int i = 0;
	std::string s;
	PhoneBook phonebook;

	while(1)
	{
		if (!std::getline(std::cin, s))
			return (0);
		if(s.compare("EXIT") == 0)
			return (0);
		else if (s.compare("ADD") == 0)
		{
			phonebook.add_contact(i % 8);
			++i;
		}
		else if (s.compare("SEARCH") == 0)
			print_contacts(phonebook);
	}
}