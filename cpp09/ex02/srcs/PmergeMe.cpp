#include "PmergeMe.hpp"

std::ostream &  operator<<(std::ostream & o, Node & rhs)
{
    rhs.printArray(o);
    // rhs.showPair(o);
	return (o);
}

int Node::getValue(){
    if(v1)
        return v1->getValue();
    return value;
}

Node *Node::getV1(){
    return v1;
}

Node *Node::getV2(){
    return v2;
}

int Node::isPair(){
    return v1 && v2;
}

void Node::showPair(std::ostream & o) {
    if (this->isPair()) {
        v1->showPair(o);
        o << "/";
        v2->showPair(o);
        o << " ";
    } else {
        o << value;
    }
}

void Node::printArray(std::ostream & o) {
    if (this->isPair()) {
        v1->printArray(o);
        o << " ";
        v2->printArray(o);
    } else {
        if (value != -1)
            o << value;
    }
}

void Node::deleteArr(){
    if (v1 && v2) {
        v1->deleteArr();
        v2->deleteArr();
    }
    delete this;
}

void	check_and_fill(int ac, char **av, std::vector<Node*> &v, std::deque<Node*> &deq)
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
            deq.push_back(new Node(atoi(av[i])));
            deq.size();
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
        deq.push_back(new Node());
        deq.size();
        ++size;
    }
}

std::vector<int> nodeSelect(int size, std::vector<int> jacob)
{
    std::vector<int> res;
    size = jacob.size();
    res.push_back(0);
    if (jacob.size() == 1)
        return res;
    res.push_back(1);
    if (jacob.size() == 2)
        return res;
    for (std::vector<int>::iterator it = jacob.begin() + 2; it != jacob.end() - 1; ++it){
        for(int i = (*it); i > (*(it - 1)); --i){
            res.push_back(i);
        }
    }
    return (res);
}

std::vector<int> generateJacobsthal(int size)
{
    std::vector<int> jacob;
    if (size <= 0)
        return (jacob.push_back(0), jacob);
    jacob.push_back(0);
    if (size == 1)
        return jacob;
    jacob.push_back(1);
    if (size == 2)
        return jacob;
    int i = 2;
    while (jacob.back() < size)
    {
        jacob.push_back(jacob.at(i-1) + 2 * jacob.at(i-2));
        ++i;
    }
    jacob.back() = size;
    return jacob;
};

std::vector<Node*>    expand(std::vector<Node*> arr)
{
    std::vector<Node*> res;
    std::vector<Node*> pend;
    for (std::vector<Node*>::iterator it = arr.begin(); it != arr.end(); ++it){
        res.push_back((*it)->getV1());
        pend.push_back((*it)->getV2());
    }
    std::vector<int> jacob = generateJacobsthal(pend.size());
    std::vector<int> order = nodeSelect(pend.size(),jacob);
    for (std::vector<int>::iterator it = order.begin(); it != order.end(); ++it){
        res.insert(res.begin() + BST<std::vector<Node*> >(res, 0, res.size() - 1, pend.at((*it))), pend.at((*it)));
    }
    if (res[0]->isPair())
        return (expand(res));
    return res;
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

std::deque<Node*>    expand(std::deque<Node*> arr)
{
    std::deque<Node*> res;
    std::deque<Node*> pend;
    for (std::deque<Node*>::iterator it = arr.begin(); it != arr.end(); ++it){
        res.push_back((*it)->getV1());
        pend.push_back((*it)->getV2());
    }
    std::vector<int> jacob = generateJacobsthal(pend.size());
    std::vector<int> order = nodeSelect(pend.size(),jacob);
    for (std::vector<int>::iterator it = order.begin(); it != order.end(); ++it){
        res.insert(res.begin() + BST<std::deque<Node*> >(res, 0, res.size() - 1, pend.at((*it))), pend.at((*it)));
    }
    if (res[0]->isPair())
        return (expand(res));
    return res;
}

std::deque<Node*>    reduce(std::deque<Node*> arr)
{
    std::deque<Node*> res;
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

void FordJohnson(std::vector<Node*> &arr){
    arr = reduce(arr);
    arr = expand(arr);
}

void FordJohnson(std::deque<Node*> &arr){
    arr = reduce(arr);
    arr = expand(arr);
}