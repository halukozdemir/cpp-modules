#include "iter.hpp"
#include <iostream>
#include <string>

void printInt(int& n)
{
    std::cout << n << " ";
}

void printConstInt(const int& n)
{
    std::cout << n << " ";
}

void printString(std::string& str)
{
    std::cout << str << " ";
}

void printConstString(const std::string& str)
{
    std::cout << str << " ";
}

template<typename T>
void print(T& value)
{
    std::cout << value << " ";
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    const int arr2[] = {10, 20, 30, 40, 50};
    std::string arr3[] = {"hello", "world", "cpp"};
    const std::string arr4[] = {"const", "string", "test"};
    
    std::cout << "Normal int array: ";
    iter(arr1, 5, printInt);
    std::cout << std::endl;
    
    std::cout << "Const int array: ";
    iter(arr2, 5, printConstInt);
    std::cout << std::endl;
    
    std::cout << "Normal string array: ";
    iter(arr3, 3, printString);
    std::cout << std::endl;
    
    std::cout << "Const string array: ";
    iter(arr4, 3, printConstString);
    std::cout << std::endl;
    
    std::cout << "Template function with int array: ";
    iter(arr1, 5, print<int>);
    std::cout << std::endl;
    
    std::cout << "Template function with string array: ";
    iter(arr3, 3, print<std::string>);
    std::cout << std::endl;
    
    return 0;
}
