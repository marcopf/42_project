// #include "Array.hpp"

// template<typename T>
// Array<T>::Array(const Array &copy)
// {
// 	*this = copy;
// }

// template<typename T>
// unsigned int Array<T>::size(void)
// {
// 	return (this->len);
// }


// template<typename T>
// T &Array<T>::operator[](const int i)
// {
// 	if (i >= 0 && i < this->len)
// 		return (this->arr[i]);
// 	else
// 		throw outOfBoundsEx();
// }

// template<typename T>
// Array<T> &Array<T>::operator=(const Array &copy)
// {
// 	delete this->arr;
// 	this->arr = new int [copy->len];
// 	for (unsigned int i = 0; i < copy.len; i++)
// 		this->arr = copy.arr[i];
// 	this->len = copy.len;
// 	return (*this);
// }

// template<typename T>
// Array<T>::Array(void)
// {
// 	this->arr = NULL;
// }

// template<typename T>
// Array<T>::Array(unsigned int len) : len(len)
// {
// 	this->arr = new int[len];
// 	for (unsigned int i = 0; i < len; i++)
// 	{
// 		this->arr[i] = 0;
// 	}
// }

// template<typename T>
// Array<T>::~Array()
// {
// 	delete this->arr;
// }