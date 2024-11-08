#pragma once

#include <iomanip>
#include <iostream>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
#include <cmath>

class Node
{
protected:
    int value;
    Node *v1;
    Node *v2;
public:
    Node():value(-1), v1(NULL), v2(NULL){};
    Node(int val):value(val), v1(NULL), v2(NULL){};
    Node(Node *n1, Node *n2):value(n1->getValue()), v1(n1), v2(n2){};
    Node(Node *n):value(n->getValue()), v1(n->getV1()), v2(n->getV2()){};
    ~Node(){};

    int getValue();
    Node *getV1();
    Node *getV2();
    int isPair(void);

    void showPair(std::ostream & o);
    void printPair(std::ostream & o);
    void printArray(std::ostream & o);
    void deleteArr();
};

std::ostream &  operator<<(std::ostream & o, Node & rhs);

void	check_and_fill(int ac, char **av, std::vector<Node*> &v, std::deque<Node*> &deq);
void    adjust(std::vector<Node*> &vec, std::deque<Node*> &deq);
std::vector<int> nodeSelect(int size, std::vector<int> jacob);  


template <typename T>
std::vector<int> generateJacobsthal(int count);

template <typename T>
int BST(T arr, int low, int high, Node *x)
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
};


std::vector<Node*>    reduce(std::vector<Node*> arr);
std::vector<Node*>    expand(std::vector<Node*> arr);

std::deque<Node*>    reduce(std::deque<Node*> arr);
std::deque<Node*>    expand(std::deque<Node*> arr);

void FordJohnson(std::vector<Node*> &arr);
void FordJohnson(std::deque<Node*> &arr);