#include "easyfind.hpp"

int main( void )
{
	int	arr[] = {0, 0, 0, 5, 0, 0};
	std::vector<int> vec(arr, arr + 6);
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2 = vec.end();

	for (it = vec.begin(); it != it2; it++)
		std::cout << *it << std::endl;

	easyfind<std::vector<int> >(vec, 5);
	return 0;
}
