#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP
# include <string>
# include <iostream>
# include <math.h>
# include <time.h>
# include <exception>

class Base { public: virtual ~Base();};

class A: public Base{};
class B: public Base{};
class C: public Base{};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
