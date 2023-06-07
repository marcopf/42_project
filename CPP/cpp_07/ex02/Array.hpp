#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
private:
	T *arr;
	unsigned int len;
public:
	class outOfBoundsEx : public std::exception
	{
		const char *what()const throw()
		{
			return ("Error: given index not in valid range");
		};
	};
public:
	Array(void)
	{
		this->arr = NULL;
	}
	Array(unsigned int len) : len(len)
	{
		this->arr = new int[len];
		for (unsigned int i = 0; i < len; i++)
		{
			this->arr[i] = 0;
		}
	}
	Array(const Array &copy)
	{
		*this = copy;
	}
	Array &operator=(const Array &copy)
	{
		delete this->arr;
		this->arr = new int [copy->len];
		for (unsigned int i = 0; i < copy.len; i++)
			this->arr = copy.arr[i];
		this->len = copy.len;
		return (*this);
	}
	unsigned int size(void)
	{
		return (this->len);
	}
	T	&operator[](const int i)
	{
		if (i >= (const int)0 && i < (const int)this->len)
			return (this->arr[i]);
		else
			throw outOfBoundsEx();
	}
	~Array()
	{
	}
};

#endif