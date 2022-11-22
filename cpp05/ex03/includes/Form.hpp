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
		void				_checkGrades(void);
		bool				_isValid(void);
	public:
		Form(void);
		Form(std::string name, int sign, int exec);
		Form(Form const & parent);
        Form & 	operator=(Form const & rhs);
		~Form(void);
		std::string 	getName(void) const;
		int			 	getGradeSign(void) const;
		int			 	getGradeExec(void) const;
		bool 			getSigned(void) const;
		void			beSigned(Bureaucrat & bureaucratUsr);
		virtual void	execute(Bureaucrat const & bureaucratUsr) const = 0;
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