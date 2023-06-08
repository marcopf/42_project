#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
private:
	std::vector<int> vect;
	unsigned int N;
public:
	void	addNumber(int val);
	int		shortestSpan();
	int		longestSpan();
	Span &operator=(const Span &copy);
	Span(const Span &copy);
	Span(unsigned int N);
	Span(void);
	~Span();
public:
	class elementOverflow : public std::exception
	{
		virtual const char *what()const throw()
		{
			return ("Error: already to many elements");
		}
	};
};

#endif