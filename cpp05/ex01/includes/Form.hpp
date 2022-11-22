#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <stdlib.h>

class Bureaucrat;
class Form
{
	private:
		std::string const	_name;
		bool				_signature;
		int	const			_gradeSign;
		int	const			_gradeExec;
		int					_checkGrade(void);
		bool				_isValid(void);
	public:
		Form(void);
		Form(std::string name, int sign, int exec);
		Form(Form const & parent);
        Form & 	operator=(Form const & rhs);
		~Form(void);
		std::string 	getName(void);
		int			 	getGradeSign(void);
		int			 	getGradeExec(void);
		bool 			getSigned(void);
		virtual void	beSigned(Bureaucrat & bureaucratUsr);
        class GradeTooHighException : public std::exception
		{
            const char	*what(void) const throw();
        };
        class GradeTooLowException : public std::exception
		{
            const char	*what(void) const throw();
        };
};

std::ostream & operator<<(std::ostream & o, Form & rhs);

#endif