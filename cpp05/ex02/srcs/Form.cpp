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

std::string Form::getName(void)
{
    return this->_name;
}

int Form::getGradeSign(void)
{
    return this->_gradeSign; 
}

int Form::getGradeExec(void)
{
    return this->_gradeExec;
}

void Form::setSigned(bool signature)
{
    this->_signature = signature;
}

bool Form::getSigned(void)
{
    return this->_signature;
}

bool Form::_isValid(void)
{
	if (_gradeSign > 150 || _gradeExec > 150 || _gradeSign < 1 || _gradeExec < 1 )
		return 0;
    return 1;
}

const char *Form::GradeTooHighException::what(void) const throw(){
    return ("Grade lower than 1, you must be either very clumsy or terribly stupid \n");
}

const char *Form::GradeTooLowException::what(void) const throw(){
    return ("Grade higher than 150, you must be either very clumsy or terribly stupid \n");
}

void	Form::beSigned(Bureaucrat & trainee)
{
	if (trainee.getGrade() <= this->_gradeSign && this->_isValid())
	{
		std::cout << trainee.getName() << " signed form " << this->_name << std::endl;
		_signature = true;
		return ;
	}
	std::cout << trainee.getName() << " couldn't sign form " << this->_name << " because there is a grade problem" << std::endl;
}

void	Form::beExecuted(Bureaucrat & trainee)
{
	if (trainee.getGrade() <= this->_gradeExec && this->_isValid())
	{
		std::cout << trainee.getName() << " executed form " << this->_name << std::endl;
		return ;
	}
	std::cout << trainee.getName() << " couldn't execute form " << this->_name << " because there is a grade problem" << std::endl;
}

void Form::_checkGrades(void)
{
    try
	{
        if (this->_gradeSign < 1 || this->_gradeExec < 1)
            throw Bureaucrat::GradeTooHighException(); 
		else if (this->_gradeSign > 150 || this->_gradeExec > 150)
            throw Bureaucrat::GradeTooLowException(); 
    }
	catch (const std::exception& e)
	{
        std::cout << e.what();
    }
}

std::ostream & operator<<(std::ostream & o, Form & rhs)
{
	o << "Form "<< rhs.getName() << ", signature : "<< rhs.getSigned() << " grade to sign : " << rhs.getGradeSign() << " grade to execute : " << rhs.getGradeExec() << ".";
	return o;
}