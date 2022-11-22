#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):_name("Phil de la compta"), _grade(50)
{
	_checkGrade();
	std::cout << "Default bureaucrat recruitment called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name), _grade(grade)
{
	_checkGrade();
	std::cout << "Specific bureaucrat recruitment called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & parent):_name(parent._name), _grade(parent._grade)
{
	_checkGrade();
	std::cout << "Copy bureaucrat recruitment called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Default bureaucrat firing called" << std::endl;
}

int	Bureaucrat::getGrade(void)
{
	return (_grade);
}

std::string	Bureaucrat::getName(void)
{
	return (_name);
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	this->_grade = rhs._grade;
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw(){
    return ("Bureaucrat: grade too high\n");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw(){
    return ("Bureaucrat: grade too high\n");
}

void	Bureaucrat::signForm(Form & form)
{
	if (form.getSigned() == false)
	{
		form.beSigned(*this);
		return ;
	}
	else
		std::cout << _name << " couldn't sign " << form.getName() << " because it is already signed" << std::endl;
}


void Bureaucrat::_checkGrade(void)
{
	if (_grade < 1)
	{
		throw Form::GradeTooHighException();
		_grade = 150;
	}
	else if (_grade > 150)
	{
		throw Form::GradeTooLowException();
		_grade = 150;
	}
}

void	Bureaucrat::upGrade(void)
{
	--_grade;
	_checkGrade();
}

void	Bureaucrat::downGrade(void)
{
	++_grade;
	_checkGrade();
}

std::ostream & operator<<(std::ostream & o, Bureaucrat & rhs){
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return (o);
}
