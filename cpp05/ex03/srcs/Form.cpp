#include "Form.hpp"

Form::Form(void): _name("A38 pass"), _signature(false), _gradeSign(75), _gradeExec(75)
{
	_checkGrades();
}

Form::Form(std::string name, int sign, int exec): _name(name), _signature(false), _gradeSign(sign), _gradeExec(exec)
{
	_checkGrades();
}

Form::Form(Form const & parent): _name(parent._name), _signature(parent._signature), _gradeSign(parent._gradeSign), _gradeExec(parent._gradeExec)
{
	_checkGrades();
}

Form::~Form()
{
}

Form & Form::operator=(Form const & rhs)
{
	_signature = rhs._signature;
	return *this;
}

std::string Form::getName(void) const
{
    return _name;
}

int Form::getGradeSign(void) const
{
    return _gradeSign; 
}

int Form::getGradeExec(void) const
{
    return _gradeExec;
}

bool Form::getSigned(void) const
{
    return _signature;
}

bool Form::_isValid(void)
{
	if (_gradeSign > 150 || _gradeExec > 150 || _gradeSign < 1 || _gradeExec < 1 )
		return 0;
    return 1;
}

const char *Form::GradeTooHighException::what(void) const throw(){
    return ("Form: grade too high\n");
}

const char *Form::GradeTooLowException::what(void) const throw(){
    return ("Form: grade too low\n");
}

void	Form::beSigned(Bureaucrat & bureaucratUsr)
{
	if (bureaucratUsr.getGrade() <= _gradeSign)
	{
		std::cout << bureaucratUsr.getName() << " signed form " << _name << std::endl;
		_signature = true;
		return ;
	}
	std::cout << bureaucratUsr.getName() << " couldn't sign " << _name << " because grade is too low" << std::endl;
}

// void	Form::execute(Bureaucrat const & executor) const
// {
// 	if (executor.getGrade() <= _gradeExec)
// 	{
// 		std::cout << executor.getName() << " executed " << _name << std::endl;
// 		execute(executor);
// 		return ;
// 	}
// 	std::cout << executor.getName() << " couldn't execute " << _name << " because grade is too low" << std::endl;
// }`

void Form::_checkGrades(void)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw Form::GradeTooHighException();
	else if (_gradeSign > 150 || _gradeExec > 150)
		throw Form::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, Form & rhs)
{
	std::string signature = (rhs.getSigned() == 0 ? "nope" : "yup");
	o << "Form \""<< rhs.getName() << "\", signature : "<< signature << ", grade to sign : " << rhs.getGradeSign() << ", grade to execute : " << rhs.getGradeExec() << ".";
	return o;
}