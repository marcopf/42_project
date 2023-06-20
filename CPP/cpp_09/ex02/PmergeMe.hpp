#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <string>
#include <unistd.h>
#include <stdlib.h>

template<typename T>
void insertion_sort(T& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

template<typename T>
void merge(T &arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeInsertionSort(T &arr, int l, int r, int k)
{
    if (l < r)
    {
        if (r - l <= k)
             insertion_sort(arr, l, r);
        else
        {
            int m = l + (r - l) / 2;
            mergeInsertionSort(arr, l, m, k);
            mergeInsertionSort(arr, m + 1, r, k);
            merge(arr, l, m, r);
        }
    }
}

class PmergeMe
{
private:
	std::vector<int> vect;
	std::deque<int> list;
	double	start, end;
public:
	double	getTime(void);
	void	deque_sort();
	void	vector_sort();
	PmergeMe(const PmergeMe &copy);
	PmergeMe(char **argv);
	PmergeMe	&operator=(const PmergeMe &cpy);
	PmergeMe(/* args */);
	~PmergeMe();
};

#endif