#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): Form("RobotomyRequestForm", 72, 45)
{
	_target = "you";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):Form("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & parent):Form("RobotomyRequestForm", 72, 45)
{
	_target = parent._target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::cout << time(NULL) << std::endl;
	if (executor.getGrade() > getGradeExec())
	{
		std::cout << executor.getName() << "can't execute the form " << getName() << std::endl;
		return ;
	}
	std::cout << "* Loud drill noises near you ears *" << std::endl;
	if (rand() % 2 == 0)
		std::cout << _target << " your Robotomy is a sucess Congratulation !!" << std::endl;
	else
		std::cout << _target << " your Robotomy is a Failure no refund possible." << std::endl;
}