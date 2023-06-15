#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Error: input some number\n";
		return (1);
	}
	double s_time1, s_time2;

	std::cout << std::fixed << std::setprecision(2);
	PmergeMe test(argv);
	test.deque_sort();
	s_time1 = test.getTime();
	test.vector_sort();
	s_time2 = test.getTime();
	std::cout << "time taken to sort " << argc << " elements with [deque]: " << s_time1 << "μs"<< std::endl;
	std::cout << "time taken to sort " << argc << " elements with [vector]: " << s_time2 << "μs" << std::endl;
}