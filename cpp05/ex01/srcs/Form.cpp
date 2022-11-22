#include "Form.hpp"

Form::Form(void): _name("A38 pass"), _signature(false), _gradeSign(75), _gradeExec(75)
{
	_checkGrade();
}

Form::Form(std::string name, int sign, int exec): _name(name), _signature(false), _gradeSign(sign), _gradeExec(exec)
{
	_checkGrade();
}

Form::Form(Form const & parent): _name(parent._name), _signature(parent._signature), _gradeSign(parent._gradeSign), _gradeExec(parent._gradeExec)
{
	_checkGrade();
}

Form::~Form()
{
}

Form & Form::operator=(Form const & rhs)
{
	_signature = rhs._signature;
	return *this;
}

std::string Form::getName(void)
{
    return _name;
}

int Form::getGradeSign(void)
{
    return _gradeSign; 
}

int Form::getGradeExec(void)
{
    return _gradeExec;
}

bool Form::getSigned(void)
{
    return _signature;
}

const char *Form::GradeTooHighException::what(void) const throw(){
    return ("Form: grade too high\n");
}

const char *Form::GradeTooLowException::what(void) const throw(){
    return ("Form: grade too low\n");
}

void	Form::beSigned(Bureaucrat & bureaucratUsr)
{
	if (_checkGrade() && bureaucratUsr.getGrade() <= _gradeSign)
	{
		std::cout << bureaucratUsr.getName() << " signed form " << _name << std::endl;
		_signature = true;
		return ;
	}
	std::cout << bureaucratUsr.getName() << " couldn't sign " << _name << " because grade is too low" << std::endl;
}

int Form::_checkGrade(void)
{
	if (_gradeSign < 1 || _gradeExec < 1)
	{
		throw Form::GradeTooHighException();
		return (1);
	}
	else if (_gradeSign > 150 || _gradeExec > 150)
	{
		throw Form::GradeTooLowException();
		return (1);
	}
	return (0);
}

std::ostream & operator<<(std::ostream & o, Form & rhs)
{
	std::string signature = (rhs.getSigned() == 0 ? "nope" : "yup");
	o << "Form \""<< rhs.getName() << "\", signature : "<< signature << ", grade to sign : " << rhs.getGradeSign() << ", grade to execute : " << rhs.getGradeExec() << ".";
	return o;
}