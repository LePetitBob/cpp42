#ifndef SERIALISATION_HPP
# define SERIALISATION_HPP
#include <string>
#include <iostream>
#include <stdint.h>

typedef struct	s_data
{
	int i;
	std::string coucou;
	float f;
}				Data;

uintptr_t	serialize(Data* ptr);
Data		*deserialize(uintptr_t raw);

#endif