#ifndef ITER_HPP
# define ITER_HPP
# include <iomanip>
# include <iostream>

template <typename T>
void iter(T *arr, int size, void func(T&))
{
	for (int i = 0; i < size; i++)
		func(arr[i]);
}

template <typename  T>
void	inc(T &x)
{
	++x;
}

#endif