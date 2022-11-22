#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern Charles;
	try
	{
		srand(time(NULL));
		Bureaucrat David( "David", 1);
		std::cout << David << std::endl;
		Form *a = Charles.makeForm("PresidentialPardonForm", "THE BOLOSS");
		Form *b = Charles.makeForm("RobotomyRequestForm", "THE BOLOSS");
		Form *c = Charles.makeForm("RobotomyRequestForm", "THE BOLOSS");
		Form *d = Charles.makeForm("PresidentialPardonForm", "THE BOLOSS");
		David.signForm(*a);
		David.signForm(*b);
		David.signForm(*c);
		David.signForm(*d);
		David.executeForm(*a);
		David.executeForm(*b);
		David.executeForm(*b);
		David.executeForm(*b);
		David.executeForm(*c);
		David.executeForm(*d);
	}
	catch (std::exception &e)
	{
		std::cerr <<  e.what() << std::endl;
	}
	return (0);
}