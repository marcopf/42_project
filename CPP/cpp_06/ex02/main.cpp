#include "Base.hpp"
#include "stdlib.h"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int random = rand() % 3;

	std::cout << random << std::endl;
	if (random == 0)
		return (new A);
	if (random == 1)
		return (new B);
	if (random == 2)
		return (new C);
	return (0);
}

void	identify(Base *ptr)
{
	if (Base *temp = dynamic_cast<A *>(ptr))
	{
		std::cout << "AAAAAA\n";
		(void)temp;
	}
	else if (Base *temp = dynamic_cast<B *>(ptr))
	{
		std::cout << "BBBBBB\n";
		(void)temp;
	}
	else if (Base *temp = dynamic_cast<C *>(ptr))
	{
		std::cout << "CCCCCC\n";
		(void)temp;
	}
}

void	identify(Base &ptr)
{
	try
	{
		Base &temp = dynamic_cast<A&>(ptr);
		(void)temp;
		std::cout << "AAAAA\n";
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	try
	{
		Base &temp = dynamic_cast<B&>(ptr);
		(void)temp;
		std::cout << "BBBBBB\n";
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	try
	{
		Base &temp = dynamic_cast<C&>(ptr);
		(void)temp;
		std::cout << "CCCCCC\n";
	}
	catch (std::exception &e)
	{
		(void)e;
	}
}

int main()
{
	srand(time(NULL));
	Base *ptr;
	ptr = generate();
	identify(ptr);
	delete ptr;
	ptr = generate();
	identify(ptr);
	delete ptr;
	ptr = generate();
	identify(ptr);
	delete ptr;
	ptr = generate();
	identify(ptr);
	delete ptr;

	ptr = generate();
	identify(*ptr);
	delete ptr;
	ptr = generate();
	identify(*ptr);
	delete ptr;
	ptr = generate();
	identify(*ptr);
	delete ptr;
	ptr = generate();
	identify(*ptr);
	delete ptr;
}