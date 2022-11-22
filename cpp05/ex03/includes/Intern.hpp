#ifndef INTERN_HPP
# define INTERN_HPP
# include "Form.hpp"
# include <iostream>
# include <string>

class Intern
{
	public:
		Intern(void);
		Intern(std::string target);
		Intern(Intern const & parent);
		Intern & operator=(Intern const & rhs);
		~Intern(void);
		Form	*makeForm(std::string form, std::string target);
		Form	*makeShruberryCreationForm(std::string target);
		Form	*makeRobotomyRequestForm(std::string target);
		Form	*makePresidentialPardonForm(std::string target);
        class BadFormException : public std::exception {
            const char	*what(void) const throw();
        };
};
typedef Form *(Intern::*funcPtr)(std::string target);

#endif