#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

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
		std::string 	getName(void);
		int			 	getGradeSign(void);
		int			 	getGradeExec(void);
		bool 			getSigned(void);
		void 			setSigned(bool signature);
		void			beSigned(Bureaucrat & trainee);
		void			beExecuted(Bureaucrat & executor);
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