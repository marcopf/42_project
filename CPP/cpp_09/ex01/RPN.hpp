#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <string>

class RPN
{
private:
	std::stack<int> mystack;
public:
	void	doOp(char *str);
	RPN(const RPN &copy);
	RPN &operator=(const RPN &copy);
	RPN(void);
	RPN(char *str);
	~RPN();
};

#endif