#include "Span.hpp"

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
	std::vector<int>::iterator it;
	int val = 0, temp = 0;

	if (this->vect.size() < 2)
		return (val);
	val = this->vect[0] - this->vect[1];
	for (unsigned int i = 0; i < this->vect.size() - 1; i++)
	{
		temp = this->vect[i] - this->vect[i + 1];
		if (temp < val)
			val = this->vect[i] - this->vect[i + 1];
	}
	return (val);
}

int		Span::longestSpan()
{
	std::vector<int>::iterator it;
	int val = 0;

	if (this->vect.size() < 2)
		return (val);
	val = this->vect[0] - this->vect[1];
	for (unsigned int i = 0; i < this->vect.size() - 1; i++)
	{
		if (this->vect[i] - this->vect[i + 1] > val)
			val = this->vect[i] - this->vect[i + 1];
	}
	return (val);
}

Span::~Span()
{
}