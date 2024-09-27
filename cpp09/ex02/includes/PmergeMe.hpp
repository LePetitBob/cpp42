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

void	check_and_fill(int ac, char **av, std::vector<int> &v, std::deque<int> &d);

template <typename T>
T generateJacobsthal(int count)
{
    T sequence(count);
    if (count > 0) sequence[0] = 0;
    if (count > 1) sequence[1] = 1;
    for (int i = 2; i < count; ++i)
        sequence[i] = sequence[i-1] + 2 * sequence[i-2];
    return sequence;
};

template <typename T>
void merge(T& arr, int left, int mid, int right)
{
    T temp(arr.size());
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (int i = left; i <= right; ++i)
        arr[i] = temp[i];
};

template <typename T>
void mergeInsertionSort(T& arr, int left, int right, const T& jacobsthal)
{
    if (left >= right)
        return;
    int n = right - left + 1;
    if (n <= 1)
        return;

    int mid = left + (right - left) / 2;

    mergeInsertionSort<T>(arr, left, mid, jacobsthal);
    mergeInsertionSort<T>(arr, mid + 1, right, jacobsthal);

    merge<T>(arr, left, mid, right);
};

template <typename T>
void mergeInsertionSort(T& arr)
{
    T jacobsthal = generateJacobsthal<T>(arr.size());
    mergeInsertionSort(arr, 0, arr.size() - 1, jacobsthal);
};