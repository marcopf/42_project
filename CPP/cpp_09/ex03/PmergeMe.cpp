#include "PmergeMe.hpp"

double	get_ts(struct timeval ts)
{
	gettimeofday(&ts, 0);
	return ((((ts.tv_sec % 100) * 1000000) + ts.tv_usec));
}

template <typename T>
int	is_sorted(T &arr)
{
	int i = -1;

	while ((unsigned int)++i < arr.size() - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
	}
	return (1);
}

PmergeMe::PmergeMe(void): start(0), end(0)
{
}

int	isPosNumber(char *str)
{
	int i = -1;

	while (str[++i])
	{
		if (!isdigit(str[i]))
			return (0);
	}
	if (atof(str) > 2147483647)
		return (0);
	return (1);
}

double	PmergeMe::getTime(void)
{
	double ret;

	ret = this->end - this->start;
	return (ret);
}

void	PmergeMe::deque_sort(void)
{
	int i = -1;
	struct timeval time;

	this->start = get_ts(time);
	mergeInsertionSort(this->list, 0, this->list.size() - 1, 4);
	this->end = get_ts(time);
	std::cout << "\n\nsorted numbers: ";
	while ((unsigned long)++i < this->vect.size())
		std::cout << this->list[i] << " ";
	std::cout << std::endl;
	if (is_sorted(this->list))
		std::cout << "\n\nproperly sorted\n\n";
	else
		std::cout << "\n\nError: list not sorted\n\n";
}

void	PmergeMe::vector_sort(void)
{
	int i = -1;
	struct timeval time;

	this->start = get_ts(time);
	mergeInsertionSort(this->vect, 0, this->vect.size() - 1, 4);
	this->end = get_ts(time);
	std::cout << "\n\nsorted numbers: ";
	while ((unsigned long)++i < this->vect.size())
		std::cout << this->vect[i] << " ";
	std::cout << std::endl;
	if (is_sorted(this->vect))
		std::cout << "\n\nproperly sorted\n\n";
	else
		std::cout << "\n\nError: list not sorted\n\n";

}

PmergeMe::PmergeMe(char **argv): start(0), end(0)
{
	int	i = 0;

	while (argv[++i])
	{
		if (isPosNumber(argv[i]))
		{
			this->vect.push_back(atoi(argv[i]));
			this->list.push_back(atoi(argv[i]));
		}
		else
		{
			std::cout << "Error: bad input\n";
			return ;
		}
	}
	i = -1;
	std::cout << "unsorted numbers: ";
	while ((unsigned long)++i < this->vect.size())
		std::cout << this->list[i] << " ";
	std::cout << std::endl;
}

PmergeMe::~PmergeMe()
{
} 