#include "Identify.hpp"

Base::~Base(void)
{
}

Base * generate(void)
{
	int i = rand() % 3;
	switch(i)
	{
		case 0:	std::cout << "a" << std::endl;
				return (new A());
		case 1:	std::cout << "b" << std::endl;
				return (new B());
		case 2:	std::cout << "c" << std::endl;
				return (new C());
	}
	return (NULL);
}

void	identify(Base* p)
{
	A* a = dynamic_cast<A *>(p);
	if (a != NULL)
	{
		std::cout << "Is A" << std::endl;
		return ;
	}
	B* b = dynamic_cast<B *>(p);
	if (b != NULL)
	{
		std::cout << "Is B" << std::endl;
		return ;
	}
	C* c = dynamic_cast<C *>(p);
	if (c != NULL)
	{
		std::cout << "Is C" << std::endl;
		return ;
	}
}

void	identify(Base& p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "Is A" << std::endl;
	}
	catch(std::exception & e)
	{
	}

	try
	{
		dynamic_cast<B &>(p);
		std::cout << "Is B" << std::endl;
	}
	catch(std::exception & e)
	{
	}

	try
	{
		dynamic_cast<C &>(p);
		std::cout << "Is C" << std::endl;
	}
	catch(std::exception & e)
	{
	}

	return ;
}



//? Base * generate(void);

//? Elle crée aléatoirement une instance de A, B ou C et la retourne en tant que pointeur sur
//? Base. Utilisez ce que vous souhaitez pour l’implémentation du choix aléatoire.


//? void identify(Base* p);

//? Elle affiche le véritable type de l’objet pointé par p : "A", "B" ou "C".


//? void identify(Base& p);

//? Elle affiche le véritable type de l’objet pointé par p : "A", "B" ou "C". Utiliser un pointeur
//? dans cette fonction est interdit.
//? Le fichier d’en-tête typeinfo est interdit.
//? Écrivez un programme pour tester que tout fonctionne comme attend