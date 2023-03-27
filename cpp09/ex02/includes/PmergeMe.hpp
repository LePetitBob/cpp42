#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iomanip>
# include <iostream>
# include <ctime>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <vector>
# include <deque>
# include <algorithm>

void	check_and_fill(int ac, char **av, std::vector<int> &v, std::deque<int> &d);

template <typename T>
void	MergeSort(T& v, int s, int e)
{
	if (s < e)
	{
		int m = (s + e) / 2;
		MergeSort(v, s, m);
		MergeSort(v, m + 1, e);
		MergeSortedIntervals(v, s, m, e);
	}
}

template <typename T>
void	MergeSortedIntervals(T& v, int s, int m, int e)
{
	T temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e)
	{
		if (v[i] <= v[j])
		{
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}
	}
	while (i <= m)
	{
		temp.push_back(v[i]);
		++i;
	}
	while (j <= e)
	{
		temp.push_back(v[j]);
		++j;
	}
	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];
}
#endif