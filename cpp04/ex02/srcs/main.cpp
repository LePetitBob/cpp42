#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main()
{
	// Animal			mammal;
	Animal 			*cat = new Cat();
	Animal			*cat2;
	Animal const	*dog = new Dog();
	WrongAnimal const	*Wrong = new WrongCat();

	// mammal.makeSound();
	cat->makeSound();
	dog->makeSound();
	cat2 = cat;
	cat2->makeSound();
	Wrong->makeSound();
	delete Wrong;
	delete dog;
	delete cat;
	return (0);
}