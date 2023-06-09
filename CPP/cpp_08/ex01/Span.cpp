#include "Span.hpp"
#include <cstdlib>

Span::Span(void) : N(0)
{
}

Span::Span(unsigned int N) : N(N)
{
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span	&Span::operator=(const Span &copy)
{
	if (this == &copy)
		return (*this);
	this->N = copy.N;
	this->vect = copy.vect;
	return (*this);
}

void	Span::addNumber(int val)
{
	if (this->vect.size() < this->N)
	{
		this->vect.push_back(val);
	}
	else
		throw(elementOverflow());
}

int		Span::shortestSpan()
{
	int val;

	if (this->vect.size() < 2)
		return (0);
	val = abs(this->vect[0] - this->vect[1]);
	for (unsigned int i = 0; i < this->vect.size() - 1; i++)
	{
		if (abs(this->vect[i] - this->vect[i + 1]) <= val)
			val = abs(this->vect[i] - this->vect[i + 1]);
	}
	return (val);
}

int		Span::longestSpan()
{
	int val;

	if (this->vect.size() < 2)
		return (0);
	val = abs(this->vect[0] - this->vect[1]);
	for (unsigned int i = 0; i < this->vect.size() - 1; i++)
	{
		if (abs(this->vect[i] - this->vect[i + 1]) >= val)
			val = abs(this->vect[i] - this->vect[i + 1]);
	}
	return (val);
}

void	Span::addRange(int start, int end)
{
	if (start < end)
	{
		while (start < end)
		{
			try
			{
				addNumber(start++);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
		}
	}
	else
	{
		while (end < start)
		{
			try
			{
				addNumber(end++);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
		}
	}
}

Span::~Span()
{
}