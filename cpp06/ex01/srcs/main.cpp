#include "Serialisation.hpp"

int main(void)
{
	Data		data;
	uintptr_t	raw;

	std::cout << "data address :		" << &data << std::endl;
	raw = serialize(&data);
	std::cout << "serialized data :	" << raw << std::endl;
	std::cout << "deserialized data :	" << deserialize(raw) << std::endl;
	return (0);
}