#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

class Contact
{
	public :

		std::string Getter_first(void);
		std::string Getter_last(void);
		std::string Getter_nick(void);
		std::string Getter_secret(void);

		void		Setter_first(std::string first);
		void		Setter_last(std::string last);
		void		Setter_nick(std::string nick);
		void		Setter_secret(std::string secret);

	private:

		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _darkest_secret;
};

class PhoneBook
{
	public :

		void	add_contact(int i);
		void	print_contacts(void);

	private:
	
		Contact contacts[8];
};
