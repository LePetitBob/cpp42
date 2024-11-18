#include "PmergeMe.hpp"

int main(int ac, char **av) {
    std::vector<Node*> vec;
    std::deque<Node*> deq;
    std::vector<int> tmp;
	struct timeval tp, tp2;

    if (ac < 2){
        std::cout << "Error:\nwrong number of arguments. Expected 2." << std::endl;
        return 1;
    }

    check_and_fill(ac, av, vec, deq);

    std::cout << "Before : ";
    for (std::vector<Node*>::iterator it=vec.begin(); it != vec.end(); it++)
        std::cout  << (*it)->getValue() << " ";
    std::cout <<std::endl;

    adjust(vec, deq);

    gettimeofday(&tp, NULL);
    if (ac > 2){
        FordJohnson(vec);
    }
    gettimeofday(&tp2, NULL);

    std::cout << "After  : ";
    for (std::vector<Node*>::iterator it=vec.begin(); it != vec.end(); it++)
        if ((*it)->getValue() != -1)
            std::cout  << (*it)->getValue() << " ";
    std::cout <<std::endl;

	unsigned long micro = tp.tv_usec + 1000000 * tp.tv_sec, micro2 = tp2.tv_usec + 1000000 * tp2.tv_sec;
    std::cout << "Time to process a range of "<< ac - 1 <<" elements with std::vector : " << micro2 - micro << " us" << std::endl;

    gettimeofday(&tp, NULL);
    if (ac > 2){
        FordJohnson(deq);
    }
    gettimeofday(&tp2, NULL);

	micro = tp.tv_usec + 1000000 * tp.tv_sec, micro2 = tp2.tv_usec + 1000000 * tp2.tv_sec;
    std::cout << "Time to process a range of "<< ac - 1 <<" elements with std::deque  : " << micro2 - micro << " us" << std::endl;

    deq[0]->deleteArr();
    vec[0]->deleteArr();
    return 0;
}


