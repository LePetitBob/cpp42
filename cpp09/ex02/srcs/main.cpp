#include "PmergeMe.hpp"

int main(int ac, char **av) {
    std::vector<Node> vec;
    std::deque<Node> deq;

    check_and_fill(ac, av, vec, deq);
    adjust(vec, deq);

	// struct timeval tp, tp2;

    // std::cout << "Before :\n";
    print_array(vec);
    while (vec.size() > 1){
        vec = reduce(vec);
        print_array(vec);
    }
    
    // gettimeofday(&tp, NULL);
    // mergeInsert(vec, 0);
    // gettimeofday(&tp2, NULL);

    for(std::vector<Node>::iterator it = vec.end() - 1; (*it).getValue() == -1; --it)
        vec.pop_back();
    // std::cout << "After : ";
    // print_array(vec);

	// unsigned long micro = tp.tv_usec + 1000000 * tp.tv_sec, micro2 = tp2.tv_usec + 1000000 * tp2.tv_sec;
    // std::cout << "Time to process a range of "<< ac - 1 <<" elements with std::vector : " << micro2 - micro << " us" << std::endl;

    // gettimeofday(&tp, NULL);
    // mergeInsertionSort<std::deque<int> >(deq);
    // gettimeofday(&tp2, NULL);

	// micro = tp.tv_usec + 1000000 * tp.tv_sec, micro2 = tp2.tv_usec + 1000000 * tp2.tv_sec;
    // std::cout << "Time to process a range of "<< ac - 1 <<" elements with std::deque : " << micro2 - micro << " us" << std::endl;
    
    return 0;
}