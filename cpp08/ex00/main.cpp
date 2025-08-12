#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
    std::cout << "=== Test 1: Vector ===" << std::endl;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found 3 at position: " << std::distance(vec.begin(), it) << std::endl;
        std::cout << "Value: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "3 not found in vector" << std::endl;
    }

    std::cout << "\n=== Test 2: List ===" << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    try
    {
        std::list<int>::iterator it = easyfind(lst, 30);
        std::cout << "Found 30 at position: " << std::distance(lst.begin(), it) << std::endl;
        std::cout << "Value: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "30 not found in list" << std::endl;
    }

    std::cout << "\n=== Test 3: Exception Test ===" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 999);
        std::cout << "Found 999 at position: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: 999 not found in vector" << std::endl;
    }

    return 0;
}
