#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	srand(time(NULL));
	Bureaucrat David( "David", 1);
	std::cout << David << std::endl;
	Bureaucrat Paul( "Paul", 147);
	std::cout << Paul << std::endl;

	PresidentialPardonForm a("Les Francais");
	RobotomyRequestForm yeay("robotomy form");
	ShrubberyCreationForm b("Shrub");

	try
	{
		Paul.signForm(a);
		Paul.signForm(yeay);
		Paul.signForm(b);
	}
	catch (std::exception &e)
	{
		std::cerr <<  e.what() << std::endl;
	}


	try
	{
		David.signForm(a);
		David.signForm(yeay);
		David.signForm(b);

		Paul.executeForm(a);
		Paul.executeForm(yeay);
		Paul.executeForm(b);

		David.executeForm(a);
		David.executeForm(yeay);
		David.executeForm(yeay);
		David.executeForm(yeay);
		David.executeForm(b);
	}
	catch (std::exception &e)
	{
		std::cerr <<  e.what() << std::endl;
	}
	return (0);
}