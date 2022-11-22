#include "Form.hpp"

int main()
{

		Bureaucrat David( "David", 1);
		std::cout << David << std::endl;

		Bureaucrat Pedro( "Pedro", 50);
		std::cout << Pedro << std::endl;
		Pedro.downGrade();
		std::cout << Pedro << std::endl;

		try
		{
			Form A("wrongform", 15, 0);
		}
		catch (std::exception &e)
		{
			std::cerr <<  e.what() << std::endl;
		}

		try
		{
			Form A("wrongform2", 151, 1);
		}
		catch (std::exception &e)
		{
			std::cerr <<  e.what() << std::endl;
		}

		try
		{
			Form b("ok form", 15, 98);
			std::cout << b << std::endl;
			std::cout << Pedro << std::endl;
			Pedro.signForm(b);
			std::cout << b << std::endl;

		}
		catch (std::exception &e)
		{
			std::cerr <<  e.what() << std::endl << std::endl;
		}

		try
		{
			Form b("ok form2", 50, 98);
			std::cout << b << std::endl;
			std::cout << Pedro << std::endl;
			Pedro.signForm(b);
			Pedro.upGrade();
			Pedro.signForm(b);
			std::cerr << b << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr <<  e.what() << std::endl << std::endl;
		}

		try
		{
			Form C("other form", 15, 40);
			std::cout << Pedro << std::endl;
			std::cout << C << std::endl;

			Pedro.signForm(C);
			std::cout << C << std::endl;

		}
		catch (std::exception &e)
		{
			std::cerr <<  e.what() << std::endl << std::endl;
		}
}