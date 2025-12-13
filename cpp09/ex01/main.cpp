#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    std::string input = argv[1];
    std::cout << RPN::calculateRPN(input) << std::endl;
    return (0);
}
