#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):Form("ShrubberyCreationForm", 145, 137)
{
	_target = "your garden";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):Form("ShrubberyCreationForm", 137, 145), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & parent):Form("ShrubberyCreationForm", 137, 145),  _target(parent._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &		ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	_target = rhs._target;
	return *this;
}

std::ostream &			operator<<(std::ostream & o, ShrubberyCreationForm const & i)
{
	o << "ShrubberyCreationForm targetting " << i.getTarget() << std::endl;
	return o;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeExec())
	{
		std::cout << executor.getName() << "can't execute the form " << getName() << std::endl;
		return ;
	}
	std::string tree = "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ *% & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _";
	std::string name = _target;
	name += "_shrubbery";
	std::ofstream ofs(name.data(), std::ofstream::out);
	if(ofs.fail())
	{
		std::cout << "Create new file Faillure" << std::endl;
		return;
	}
	ofs << tree;
	ofs.close();
}

std::string ShrubberyCreationForm::getTarget() const
{
	return(_target);
}