#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const & parent);
        Bureaucrat & 	operator=(Bureaucrat const & rhs);
        ~Bureaucrat();
        std::string		getName(void);
        int 			getGrade(void);
        void 			upGrade(void);
        void 			downGrade(void);
        class GradeTooHighException : public std::exception
		{
            const char	*what(void) const throw();
        };
        class GradeTooLowException : public std::exception
		{
            const char	*what(void) const throw();
        };
    private:
        const std::string _name;
        int _grade;
        void _checkGrade(void);

};

std::ostream & operator<<(std::ostream & o, Bureaucrat & rhs);


#endif