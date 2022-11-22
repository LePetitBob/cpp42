#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"
# include <iostream>
# include <string>

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & parent);
		std::string getTarget(void) const;
		PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
		~PresidentialPardonForm(void);
		void execute(Bureaucrat const & executor) const;
	private:
		std::string _target;
};

std::ostream &			operator<<(std::ostream & o, PresidentialPardonForm const & i);

#endif