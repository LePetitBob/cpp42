#include "Bureaucrat.hpp"

int main(void){
    Bureaucrat a("Patrick", 0);
    Bureaucrat b;
    Bureaucrat c("Tommy", 1);
    Bureaucrat d;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
	d = c;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    c.upGrade();
    a.downGrade();
    std::cout << c << std::endl;
    std::cout << a << std::endl;
    return 0;
}