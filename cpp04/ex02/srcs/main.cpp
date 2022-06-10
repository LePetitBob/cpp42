#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main()
{
	// Animal			mammal;
	Animal const	*cat = new Cat();
	Animal const	*dog = new Dog();
	WrongAnimal const	*Wrong = new WrongCat();

	// mammal.makeSound();
	cat->makeSound();
	dog->makeSound();
	Wrong->makeSound();
	delete Wrong;
	delete dog;
	delete cat;
	return (0);
}