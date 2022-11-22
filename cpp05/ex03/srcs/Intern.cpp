#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(Intern const & parent)
{
	(void)parent;
}

Intern::~Intern()
{
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return *this;
}

Form *Intern::makeShruberryCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(std::string form, std::string target)
{
    std::string tab[3] = { "ShruberryCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    funcPtr fct[3] = { &Intern::makeShruberryCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
    int i;

    for (i = 0; i < 3; i++)
    {   

        if (form.compare(tab[i]) == 0)
            break;
    }
    if (i == 3)
        throw Intern::BadFormException();
    else
        return ((this->*(fct[i]))(target));
}

const char *Intern::BadFormException::what(void) const throw(){
    return ("Intern can't create this form\n");
}
