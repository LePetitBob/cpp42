#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"
# include <fstream>
# include <iostream>
# include <string>

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & parent);
		std::string getTarget() const;
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
		~ShrubberyCreationForm(void);
		void execute(Bureaucrat const & executor) const;
	private:
		std::string _target;
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & i);

#endif