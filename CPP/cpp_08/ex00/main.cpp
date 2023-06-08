#include "easyfind.tpp"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>

int main()
{
	srand(time(NULL));
	std::vector<int> numbers(10, 0);
	for (int i = 0; i < 10; i++)
		numbers[i] = rand() % 20;
	for (int i = 0; i < 10; i++)
		std::cout << numbers[i] << " ";
	int j = rand() % 20;
	int i = easyFind(numbers, j);
	if (i)
		std::cout << std::endl << j << ": si trova nel vettore\n";
	else
		std::cout << std::endl << j << ": NON si trova nel vettore\n";
}