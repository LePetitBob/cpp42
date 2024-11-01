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
    int getValue(){
        if(v1)
            return v1->getValue();
        return value;
    };

    Node *getV1(){
        if (v1)
            return v1;
        return NULL;
    };
    Node *getV2(){
        if (v2)
            return v2;
        return NULL;
    };

    int isPair(void){return (v1 && v2);};

    void showPair(std::ostream & o) {
        if (this->isPair()) {
            v1->showPair(o);
            o << "/";
            v2->showPair(o);
            o << " ";
        } else {
            o << value;
        }
    };

    void deleteArr(){
        if (v1 && v2) {
            v1->deleteArr();
            v2->deleteArr();
        }
        delete this;
    };
};

std::ostream &  operator<<(std::ostream & o, Node & rhs);

std::vector<Node*>    reduce(std::vector<Node*> arr);
void	check_and_fill(int ac, char **av, std::vector<Node*> &v, std::deque<Node*> &d);
void    adjust(std::vector<Node*> &vec, std::deque<Node*> &deq);
// void    print_array(std::vector<Node*> &arr);
// void    print_array(std::deque<int> arr);
// void mergeInsert(std::vector<Node*> &arr, int depth);

int generateJacobsthal(int count);

// template <typename T>
// void merge(T& arr, int left, int mid, int right)
// {
//     T temp(arr.size());
//     int i = left, j = mid + 1, k = left;

//     while (i <= mid && j <= right)
//     {
//         if (arr[i] <= arr[j])
//             temp[k++] = arr[i++];
//         else
//             temp[k++] = arr[j++];
//     }
//     while (i <= mid)
//         temp[k++] = arr[i++];
//     while (j <= right)
//         temp[k++] = arr[j++];
//     for (int i = left; i <= right; ++i)
//         arr[i] = temp[i];
// };

// template <typename T>
// void mergeInsert(T& arr, int left, int right, const T& jacobsthal)
// {
//     if (left >= right)
//         return;
//     int n = right - left + 1;
//     if (n <= 1)
//         return;

//     int mid = left + (right - left) / 2;

//     mergeInsert<T>(arr, left, mid, jacobsthal);
//     mergeInsert<T>(arr, mid + 1, right, jacobsthal);

//     merge<T>(arr, left, mid, right);
// };


// template <typename T>
// void mergeInsert(T& arr)
// {
//     mergeInsert(arr, 0, arr.size() - 1, jacobsthal);
// };