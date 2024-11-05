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
    if (res.size() == 1)
        return res;
    return reduce(res);
}

int BST(std::vector<Node*> arr, int low, int high, Node *x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr.at(mid)->getValue() == x->getValue())
            return mid;
        if (arr.at(mid)->getValue() < x->getValue())
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

std::vector<Node*>::iterator getIterator(std::vector<Node*> arr, int index)
{
    std::vector<Node*>::iterator it = arr.begin();
    for (int i = 0; i < index; ++i){
        ++it;
    }
    return it;
}

Node    *nodeSelect(std::vector<Node*> pend, std::vector<int> jacob)
{
    int size = pend.size();
    
    return (pend[0]);
}

std::vector<Node*>    expand(std::vector<Node*> arr)
{
    std::vector<Node*> res;
    std::vector<Node*> pend;
    // int size = arr.size(), i = 0, count = 0, j = 0, j1, j2;
    for (std::vector<Node*>::iterator it = arr.begin(); it != arr.end(); ++it){
        res.push_back((*it)->getV1());
        pend.push_back((*it)->getV2());
    }
    unsigned long count= 0;
    std::vector<int> jacob = generateJacobsthal(pend.size());
    while (pend.size() > 0){
        Node *node = nodeSelect(pend,jacob);
        res.insert(res.begin() + BST(res, 0, res.size() - 1, node), node);
        ++count;
    }
    if (res[0]->isPair())
        return (expand(res));
    return res;
}

std::vector<int> generateJacobsthal(int size)
{
    std::vector<int> jacob;
    if (size <= 0)
        return (jacob.push_back(0), jacob);
    jacob.push_back(0);
    jacob.push_back(1);
    int i = 2;
    while (jacob.back() < size)
    {
        jacob.push_back(jacob.at(i-1) + 2 * jacob.at(i-2));
        ++i;
    }
    jacob.back() = size;
    return jacob;
};

std::ostream &  operator<<(std::ostream & o, Node & rhs)
{
    rhs.printArray(o);
    // rhs.showPair(o);
	return (o);
}
