#include "PmergeMe.hpp"

int main(int ac, char **av) {
    std::vector<Node*> vec;
    std::deque<Node*> deq;
    std::vector<int> tmp;

    check_and_fill(ac, av, vec, deq);
    adjust(vec, deq);

    tmp.push_back(1);
    tmp.push_back(2);
    tmp.push_back(5);
    tmp.push_back(6);
    tmp.push_back(8);
    // Node *tmp = new Node(4);

    // std::cout << BST(vec, 0, vec.size() - 1, tmp) << std::endl;

    // std::vector<Node*>::const_iterator it = getIterator(vec, BST(vec, 0, vec.size() - 1, tmp));

    // vec.insert(vec.begin()+ BST(vec, 0, vec.size() - 1, tmp), tmp);

    // vec = reduce(vec);

        std::cout << tmp.back()<< std::endl;
    std::vector<int> jacob = generateJacobsthal(8);
    // while (1)
    // {
    //     j = generateJacobsthal(i);
    //     if (j >= size)
    //     {
    //         jacob.push_back(size);
    //         break ;
    //     }
    //     jacob.push_back(j);
    //     ++i;
    // }
    for (std::vector<int>::iterator it=jacob.begin(); it != jacob.end(); it++)
        std::cout  << (*it)<< " ";
    std::cout <<std::endl;

    // std::cout << "final value after reduction : "<<vec[0]->getValue() << "\n" << std::endl;
    
    // std::cout << (*vec[0]) << std::endl;

    // vec = expand(vec);
    
    // for(std::vector<Node*>::iterator it = vec.begin(); it !=vec.end(); ++it)
    // {
    //     if ((*it)->getValue() == -1)
    //         vec.erase(it);
    //     std::cout << (*it)->getValue() << " ";
    // }
    // std::cout << std::endl;
    // for(std::vector<Node*>::iterator it = vec.begin(); it !=vec.end(); ++it)
    // {
    //     if ((*it)->getValue() == -1)
    //         vec.erase(it);
    //     std::cout << (*it)->getValue() << " ";
    // }
    // std::cout << std::endl;

    deq[0]->deleteArr();
    vec[0]->deleteArr();
    return 0;
}


































	// struct timeval tp, tp2;

    // gettimeofday(&tp, NULL);
    // mergeInsert(vec, 0);
    // gettimeofday(&tp2, NULL);

    // for(std::vector<Node*>::iterator it = vec.end() - 1; (*it)->getValue() == -1; --it)
    //     vec.pop_back();
    // std::cout << "MORTECOUILLE" << std::endl;
    // std::cout << "After : ";
    // print_array(vec);

	// unsigned long micro = tp.tv_usec + 1000000 * tp.tv_sec, micro2 = tp2.tv_usec + 1000000 * tp2.tv_sec;
    // std::cout << "Time to process a range of "<< ac - 1 <<" elements with std::vector : " << micro2 - micro << " us" << std::endl;

    // gettimeofday(&tp, NULL);
    // mergeInsertionSort<std::deque<int> >(deq);
    // gettimeofday(&tp2, NULL);

	// micro = tp.tv_usec + 1000000 * tp.tv_sec, micro2 = tp2.tv_usec + 1000000 * tp2.tv_sec;
    // std::cout << "Time to process a range of "<< ac - 1 <<" elements with std::deque : " << micro2 - micro << " us" << std::endl;