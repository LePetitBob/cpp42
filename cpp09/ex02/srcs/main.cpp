#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	std::vector<int> v;
	std::deque<int> d;

	check_and_fill(ac, av, v, d);

	std::cout << "Before : ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << (*it) << " ";
	std::cout << std::endl;

	struct timeval tp, tp2;

    gettimeofday(&tp, NULL);
	MergeSort<std::vector<int>>(v, 0, v.size() - 1);
    gettimeofday(&tp2, NULL);

	std::cout << "After  : ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << (*it) << " ";
	std::cout << std::endl;

	unsigned long micro = tp.tv_usec + 1000000 * tp.tv_sec, micro2 = tp2.tv_usec + 1000000 * tp2.tv_sec;
    std::cout << "Time to process a range of "<< ac - 1 <<" elements with std::vector : " << micro2 - micro << " us" << std::endl;

    gettimeofday(&tp, NULL);
	MergeSort<std::deque<int>>(d, 0, d.size() - 1);
	gettimeofday(&tp2, NULL);
	
	micro = tp.tv_usec + 1000000 * tp.tv_sec;
	micro2 = tp2.tv_usec + 1000000 * tp2.tv_sec;
    std::cout << "Time to process a range of "<< ac - 1 <<" elements with std::deque  : " << micro2 - micro << " us" << std::endl;
	return (0);
}