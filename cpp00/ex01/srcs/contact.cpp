#include "phonebook.hpp"

std::string Contact::Getter_first()
{
	return (_firstname);
}

std::string Contact::Getter_last()
{
	return (_lastname);
}

std::string Contact::Getter_nick()
{
	return (_nickname);
}

std::string Contact::Getter_secret()
{
	return (_darkest_secret);
}

void Contact::Setter_first(std::string first)
{
	_firstname = first;
}

void Contact::Setter_last(std::string last)
{
	_lastname = last;
}

void Contact::Setter_nick(std::string nick)
{
	_nickname = nick;
}

void Contact::Setter_secret(std::string secret)
{
	_darkest_secret = secret;
}