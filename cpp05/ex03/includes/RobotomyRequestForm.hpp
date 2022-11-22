#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"
# include <iostream>
# include <string>
# include <cstdlib>
# include <time.h>

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & parent);
		RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);
		~RobotomyRequestForm(void);
		std::string getTarget(void) const;
		void execute(Bureaucrat const & executor) const;
	private:
		std::string _target;
};

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & i);

#endif