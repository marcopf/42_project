#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const RPN &cpy)
{
	*this = cpy;	
}

RPN &RPN::operator=(const RPN &cpy)
{
	if (this == &cpy)
		return (*this);
	this->mystack = cpy.mystack;
	return (*this);
}

void	RPN::doOp(char *str)
{
	int temp;

	while (*str && mystack.size() > 1)
	{
		if (*str == '*')
		{
			temp = mystack.top();
			mystack.pop();
			mystack.top() = temp * mystack.top();
			break ;
		}
		else if (*str == '/')
		{
			temp = mystack.top();
			mystack.pop();
			mystack.top() = temp / mystack.top();
			break ;
		}
		else if (*str == '+')
		{
			temp = mystack.top();
			mystack.pop();
			mystack.top() = temp + mystack.top();
			break ;
		}
		else if (*str == '-')
		{
			temp = mystack.top();
			mystack.pop();
			mystack.top() = mystack.top() - temp;
			break ;
		}
		str++;
	}

}

RPN::RPN(char *str)
{
	while (*str)
	{
		if (isdigit(*str))
			mystack.push(*str - 48);
		else if (strchr("+-/*", *str))
			doOp(str);
		else if (strchr("+-/* ", *str) == 0)
		{
			std::cout << "Error: bad input\n";
			return ;
		}
		str++;
	}
	std::cout << mystack.top() << std::endl;
}

RPN::~RPN()
{
}