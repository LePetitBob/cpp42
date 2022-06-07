#include "phonebook.hpp"

void	PhoneBook::add_contact(int i)
{
	std::string buff;

	std::cout << "\nFirst name		:\n>";
	std::getline(std::cin, buff);
	contacts[i].Setter_first(buff);
	std::cout << "\nLast name		:\n>";
	std::getline(std::cin, buff);
	contacts[i].Setter_last(buff);
	std::cout << "\nNickname		:\n>";
	std::getline(std::cin, buff);
	contacts[i].Setter_nick(buff);
	std::cout << "\nDarkest secret		:\n>";
	std::getline(std::cin, buff);
	contacts[i].Setter_secret(buff);
	std::cout << std::endl;
}

void	PhoneBook::print_contacts(void)
{
	std::string	index_str;
	int			index;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "|";
		std::cout << std::right << std::setw(10) << i + 1;
		std::cout << "|";
		if (contacts[i].Getter_first().size() > 10)
			std::cout << std::right << std::setw(9) << contacts[i].Getter_first().substr(0, 9) << ".";
		else
			std::cout << std::right << std::setw(10) << contacts[i].Getter_first();
		std::cout << "|";
		if (contacts[i].Getter_last().size() > 10)
			std::cout << std::right << std::setw(9) << contacts[i].Getter_last().substr(0, 9) << ".";
		else
			std::cout << std::right << std::setw(10) << contacts[i].Getter_last();
		std::cout << "|";
		if (contacts[i].Getter_nick().size() > 10)
			std::cout << std::right << std::setw(9) << contacts[i].Getter_nick().substr(0, 9) << ".";
		else
			std::cout << std::right << std::setw(10) << contacts[i].Getter_nick();
		std::cout << "|\n";
	}
	std::cout << "\nIndex of the contact you want to display : \n";
	if (!std::getline(std::cin, index_str) || (index_str.size() != 1 || index_str.at(0) > '9' ||index_str.at(0) < '0'))
		return ;
	index = atoi(index_str.c_str()) - 1;
	std::cout << "\nFirst name			: " << this->contacts[index].Getter_first() << "\n";
	std::cout << "Last name			: " << this->contacts[index].Getter_last() << "\n";
	std::cout << "Nickname			: " << this->contacts[index].Getter_nick() << "\n";
	std::cout << "Darkest secret			: " << this->contacts[index].Getter_secret() << "\n";
	std::cout << std::endl;
}

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
			phonebook.print_contacts();
	}
}