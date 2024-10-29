#include "PmergeMe.hpp"

void	check_and_fill(int ac, char **av, std::vector<Node> &v, std::deque<Node> &d)
{
    Node n;
	for (int i = 1; i < ac; i++)
	{
		for (size_t j = 0; j < strlen(av[i]); j++)
		{
			if ((j == 0 && av[i][j] != '+' && !isdigit(av[i][j])) || !isdigit(av[i][j]))
			{
				std::cout << "Error\nInvalid arguments. Must be only positive integers" << std::endl;
				exit(1);
			}
		}
		long value = atol(av[i]);
		if (strlen(av[i]) > 11 || value <= 0 || value > 2147483647)
		{
			std::cout << "Error\nOut of range. Must be only positive integers" << std::endl;
			exit(1);
		}
        std::vector<Node>::iterator it = v.begin();
        while(it != v.end())
        {
            if ((*it).getValue() == atoi(av[i]))
                break ;
            ++it;
        }
        if (it == v.end())
        {
            v.push_back(Node(atoi(av[i]), -1));
            d.push_back(Node(atoi(av[i]), -1));
        }
	}
}

void    adjust(std::vector<Node> &vec, std::deque<Node> &deq)
{
    int size = vec.size(), n = 0;
    while (size > pow(2, n))
        ++n;
    while (size < pow(2, n))
    {
        vec.push_back(Node());
        deq.push_back(Node());
        ++size;
    }
}

std::vector<Node>    reduce(std::vector<Node> arr)
{
    std::vector<Node> res;
    int size = arr.size() / 2, i = 0, v1, v2;
    while (i < size)
    {
        v1 = arr.at(i).getValue();
        v2 = arr.at(i + size).getValue();
        if (v1 > v2)
            res.push_back(Node(v1, v2));
        else
            res.push_back(Node(v2, v1));
        ++i;
    }
    return res;
}

void    print_array(std::vector<Node> &arr)
{
    for (std::vector<Node>::iterator it = arr.begin(); it != arr.end(); ++it)
        std::cout << (*it).getValue() << "/" << (*it).getPair() << "\t";
    std::cout << std::endl;
}

// void mergeInsert(std::vector<Node> &arr, int depth)
// {
//     //! remove v
//     std::cout << std::endl;
//     print_array(arr);
//     //! remove ^
 
//     ++depth;
//     int size = arr.size() / pow(2, depth);
//     if (size == 0)
//         return;
//     std::cout << "depth : " << depth << "\nsize : " << size << std::endl;
//     for(int i = 0; i < size; ++i)
//     {
//         if (arr.at(i) < arr.at(i + size))
//         {
//             ft_swap(arr.at(i), arr.at(i + size));
//         }
//     }
//     mergeInsert(arr, depth);
// }

