#include <iomanip>
#include <iostream>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <vector>
#include <utility>
#include <algorithm>

// void	check_and_fill(int ac, char **av, std::vector<int> &v, std::deque<int> &d)
// {
// 	for (int i = 1; i < ac; i++)
// 	{
// 		for (size_t j = 0; j < strlen(av[i]); j++)
// 		{
// 			if ((j == 0 && av[i][j] != '+' && !isdigit(av[i][j])) || !isdigit(av[i][j]))
// 			{
// 				std::cout << "Error\nInvalid arguments. Must be only positive integers" << std::endl;
// 				exit(1);
// 			}
// 		}
// 		long value = atol(av[i]);
// 		if (strlen(av[1]) > 11 || value < 0 || value > 2147483647)
// 		{
// 			std::cout << "Error\nOut of range. Must be only positive integers" << std::endl;
// 			exit(1);
// 		}
// 		v.push_back(atoi(av[i]));
// 		d.push_back(atoi(av[i]));
// 	}
// }

void	check_and_fill(int ac, char **av, std::vector<int> &v)//, std::deque<int> &d)
{
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
		if (strlen(av[1]) > 11 || value < 0 || value > 2147483647)
		{
			std::cout << "Error\nOut of range. Must be only positive integers" << std::endl;
			exit(1);
		}
		v.push_back(atoi(av[i]));
		// d.push_back(atoi(av[i]));
	}
}

int     is_sorted(std::vector<int> vec)
{
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        if (it + 1 != vec.end() && (*it) > (*(it + 1)))
            return (0);
    }
    return (1);
}

void    swap_pairs(std::vector<std::pair<int, int> >::iterator it)
{
    std::pair<int, int> tmp;

    tmp.first = (*it).first;
    tmp.second = (*it).second;
    (*it).first = ((*(it+1))).first;
    (*it).second = ((*(it+1))).second;
    ((*(it+1))).first = tmp.first;
    ((*(it+1))).second = tmp.second;
    return ;
}

void fordJohnsonV(std::vector<int> &vec)
{
    int last, size = vec.size();
    std::vector< std::pair <int, int> > pairs;

    if (size == 1 || is_sorted(vec))
        return ;
    if (size % 2 != 0)
    {
        last = *(vec.end());
        vec.pop_back();
        size--;
    }
    for (int i = 0; size > 0; i += 2)
    {
        int j = 0;
        if (vec.at(i) < vec.at(i + 1))
            pairs.push_back(std::make_pair(vec.at(i), vec.at(i + 1)));
        else
            pairs.push_back(std::make_pair(vec.at(i + 1), vec.at(i)));
        j++;
        size -= 2;
    }

    for (std::vector< std::pair <int, int> >::iterator iter = pairs.begin(); iter != pairs.end() ; iter++)
        std::cout << (*(iter)).first << " " << (*(iter)).second << "\n";
    std::cout << "\n" << std::endl;

    for (std::vector< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        if (it + 1 != pairs.end() && (*it).second < ((*(it+1)).second))
        {
            swap_pairs(it);
            it = pairs.begin();
        }
    }

    for (std::vector< std::pair <int, int> >::iterator iter = pairs.begin(); iter != pairs.end() ; iter++)
        std::cout << (*(iter)).first << " " << (*(iter)).second << "\n";
    std::cout << "\n" << std::endl;
}

int main(int ac, char **av)
{
    // (void)ac;
    // (void)av;

    // static const int arr[] = {1, 2, 7, 5};
    // static const int arr[] = {8, 4, 2, 3, 9, 5, 0, 1};
    // static const int arr[] = {8, 1, 2, 9, 7, 5, 0, 1};
    // std::vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    std::vector<int> vec;
	check_and_fill(ac, av, vec);

    for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end() ; iter++)
        std::cout << *(iter) << " ";
    std::cout << "\n" << std::endl;

    fordJohnsonV(vec);

    for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end() ; iter++)
        std::cout << *(iter) << " ";
    std::cout << "\n" << std::endl;


    return 0;
}