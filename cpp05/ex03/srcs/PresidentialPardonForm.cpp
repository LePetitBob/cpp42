#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form("PresidentialPardonForm", 25, 5)
{
	_target = "you";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):Form("PresidentialPardonForm", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & parent):Form("PresidentialPardonForm", 25, 5)
{
	_target = parent._target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeExec())
	{
		std::cout << executor.getName() << "can't execute the form " << getName() << std::endl;
		return ;
	}
	std::cout << "BE HONORED CITIZEN OF THE GALAXY REPUBLIC ! THE GREAT AND MAGNIFICENT ZAPHOD BEEBLEBROX DECIDED TO PARDON YOU, " << _target << std::endl;
}