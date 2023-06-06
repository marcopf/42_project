#include "Array.hpp"

int main()
{
	Array<int> arr(10);

	arr[2] = 22;
	std::cout << arr.size() << arr[2] << std::endl;
}