#include "PmergeMe.hpp"

void	check_and_fill(int ac, char **av, std::vector<Node*> &v, std::deque<Node*> &d)
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
        std::vector<Node*>::iterator it = v.begin();
        while(it != v.end())
        {
            if ((*it)->getValue() == atoi(av[i]))
                break ;
            ++it;
        }
        if (it == v.end())
        {
            v.push_back(new Node(atoi(av[i])));
            // d.push_back(new Node(atoi(av[i])));
            d.size();
        }
	}
}

void    adjust(std::vector<Node*> &vec, std::deque<Node*> &deq)
{
    int size = vec.size(), n = 0;
    while (size > pow(2, n))
        ++n;
    while (size < pow(2, n))
    {
        vec.push_back(new Node());
        // deq.push_back(new Node());
        deq.size();
        ++size;
    }
}



std::vector<Node*>    reduce(std::vector<Node*> arr)
{
    std::vector<Node*> res;
    int size = arr.size(), i = 0;
    Node *v1, *v2;
    while (i < size)
    {
        v1 = arr.at(i);
        v2 = arr.at(i + 1);
        if (v1->getValue() > v2->getValue())
            res.push_back(new Node(v1, v2));
        else
            res.push_back(new Node(v2, v1));
        i += 2;
    }
    return res;
}

// void    dichotomicSearch(std::vector<Node*> &arr, Node *n)
// {
// }

// void BST(std::vector<Node*> &arr)
// {
//     int value = n->getV2()->getValue();
//     if(arr.size() == 0)
//         arr.push_back(new Node(n));
//     // if(arr.size() == 1)
//     //     arr.push_back(new Node(n->getV2()));
//     else if(n->getValue() < n->getValue())
//         n->left = insert(n->getValue(), n->left);
//     else if(n->getValue() > n->getValue())
//         n->right = insert(n->getValue(), n->right);
//     else
//         arr.insert()
// }

// std::vector<Node*>    expand(std::vector<Node*> arr)
// {
//     std::vector<Node*> res;
//     int size = arr.size(), i = 0, count = 0, j = 0, j1, j2;

//     // if (size == 0){
//     //     res.push_back(new Node(arr[0]->getV1()));
//     // }

//     while (count < size){
//         // j1 = generateJacobsthal(j) - 1;
//         // j2 = generateJacobsthal(j + 1) - 1;
//         // if (j2 > size)
//         //     j2 = size - 1;
//         // while (j1 > j2)
//         // {
//         //     j2 = generateJacobsthal(i) - generateJacobsthal(i - 1);
//         //     --j2;
//         //     dichotomicSearch(res, arr[j2]);
//         // }
//         // i += j2-j1;
//         // ++j;
//         // BST(res);
//         ++count;
//     }

//     return res;
// }

int generateJacobsthal(int count)
{
    if (count <= 0)
        return 0;
    std::vector<int> sequence;
    sequence.push_back(0);
    sequence.push_back(1);
    for (int i = 2; i < count; ++i)
        sequence.push_back(sequence.at(i-1) + 2 * sequence.at(i-2));
    return sequence.at(count-1);
};

std::ostream &  operator<<(std::ostream & o, Node & rhs)
{
    rhs.showPair(o);
	return (o);
}



// void mergeInsert(std::vector<Node*> &arr, int depth)
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

