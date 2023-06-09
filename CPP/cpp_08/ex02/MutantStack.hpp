#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack<T>(void)
	{
		return ;
	};
	MutantStack<T>(const MutantStack &copy)
	{
		*this = copy;
	}
	MutantStack<T>	&operator=(const MutantStack<T> &copy)
	{
		if (this == copy)
			return (*this);
		this->c = copy.c;
		return (*this);
	}
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator	end(void)
	{
		return (this->c.end());
	}
	iterator	begin(void)
	{
		return (this->c.begin());
	}
	~MutantStack<T>()
	{
		return ;
	};
};

#endif