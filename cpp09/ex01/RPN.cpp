#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    (void)other;
    return *this;
}

RPN::~RPN()
{
}

int RPN::calculateRPN(std::string& str)
{
    std::stack<int> stack;
    int result = 0;
    std::string::iterator it;
    std::string keys = "+-*/";
    for (it = str.begin(); it != str.end(); ++it)
    {
        if (*it == ' ')
            continue ;
        if (keys.find(*it) == std::string::npos)
        {
            if (isdigit(*it))
                stack.push(atoi(std::string(1, *it).c_str()));
            else
            {
                std::cerr << "Error: Invalid Arguments" << std::endl;
                exit(1);
            }
        }
        else
        {
            if (stack.size() >= 2)
            {
                int tempA = stack.top();
                stack.pop();
                int tempB = stack.top();
                stack.pop();
                if (*it == '+')
                    result = tempB + tempA;
                else if (*it == '-')
                    result = tempB - tempA;
                else if (*it == '*')
                    result = tempB * tempA;
                else if (*it == '/')
                {
                    if (tempA == 0)
                    {
                        std::cerr << "Error: Division by 0" << std::endl;
                        exit(1);
                    }
                    result = tempB / tempA;
                }
                stack.push(result);
            }
            else
            {
                std::cerr << "Error: Invalid Arguments" << std::endl;
                exit(1);
            }
        }
    }
    if (stack.size() == 1)
        return stack.top();
    std::cerr << "Error: Invalid Arguments" << std::endl;
    exit(1);
}
