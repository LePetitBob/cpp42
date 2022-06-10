#include "Form.hpp"

int main(void){
    Bureaucrat  a("Patrick", 150);
    Bureaucrat  b("Francis", 1);
    Bureaucrat  c("Tommy", 75);
    Form        A("POLE_EMPLOI", 5, 5);
    Form        B;
    Form        C("guide touristique", 130, 60);
    Form        D("guide touristique nul", 150, 152);
    Form        E("guide touristique des nullos", 152, 150);

    std::cout << A << std::endl;
    std::cout << B << std::endl;
    std::cout << C << std::endl;
    std::cout << D << std::endl;
    std::cout << E << std::endl;
    a.signForm(A);
    b.signForm(A);
    c.signForm(A);
    B = A;
    B.beSigned(b);
    C.beSigned(c);
    C.beExecuted(c);
    D.beExecuted(b);
    D.beSigned(b);
    std::cout << "\n" << A << "\n" << std::endl;
    std::cout << B << "\n" << std::endl;
    std::cout << C << "\n" << std::endl;
    std::cout << D << "\n" << std::endl;
    return 0;
}