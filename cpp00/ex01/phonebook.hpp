#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
	public:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string darkest_secret;

	private:
};

class PhoneBook
{
	public:
		Contact contacts[8];
		void	add_contact(int i)
		{
			std::cout << "\nFirst name		:\n>";
			if (!std::getline(std::cin, contacts[i].firstname))
				return ;
			std::cout << "\nLast name		:\n>";
			if (!std::getline(std::cin, contacts[i].lastname))
				return ;
			std::cout << "\nNickname		:\n>";
			if (!std::getline(std::cin, contacts[i].nickname))
				return ;
			std::cout << "\nDarkest secret	:\n>";
			if (!std::getline(std::cin, contacts[i].darkest_secret))
				return ;
			std::cout << std::endl;
		}
	private:
};


void	init_contacts(int i, PhoneBook phonebook)
{
	for (int j = 0; j < 8; j++)
	{
		std::cin >> phonebook.contacts[i].firstname;
		std::cin >> phonebook.contacts[i].lastname;
		std::cin >> phonebook.contacts[i].nickname;
		std::cin >> phonebook.contacts[i].darkest_secret;
	}
};

void	print_short(std::string str)
{
	std::cout << std::right << std::setw(9) << str.substr(0, 9) << ".";
}

void	print_contacts(PhoneBook &phonebook)
{
	std::string	index_str;
	int			index;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "|";
		std::cout << std::right << std::setw(10) << i + 1;
		std::cout << "|";
		if (phonebook.contacts[i].firstname.size() > 10)
			print_short(phonebook.contacts[i].firstname);
		else
			std::cout << std::right << std::setw(10) << phonebook.contacts[i].firstname;
		std::cout << "|";
		if (phonebook.contacts[i].lastname.size() > 10)
			print_short(phonebook.contacts[i].lastname);
		else
			std::cout << std::right << std::setw(10) << phonebook.contacts[i].lastname;
		std::cout << "|";
		if (phonebook.contacts[i].nickname.size() > 10)
			print_short(phonebook.contacts[i].nickname);
		else
			std::cout << std::right << std::setw(10) << phonebook.contacts[i].nickname;
		std::cout << "|\n";
	}
	std::cout << "\nIndex of the contact you want to display : \n";
	if (!std::getline(std::cin, index_str) || (index_str.size() != 1 || index_str.at(0) > '9' ||index_str.at(0) < '0'))
		return ;
	index = std::stoi(index_str) - 1;
	std::cout << "\nFirst name			: " << phonebook.contacts[index].firstname << "\n";
	std::cout << "Last name			: " << phonebook.contacts[index].lastname << "\n";
	std::cout << "Nickname			: " << phonebook.contacts[index].nickname << "\n";
	std::cout << "Darkest secret	: " << phonebook.contacts[index].darkest_secret << "\n";
	std::cout << std::endl;
}