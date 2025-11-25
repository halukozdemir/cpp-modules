#include "Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cout << "=== Test 1: Basic Functionality ===" << std::endl;
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    
    std::cout << "\n=== Test 2: Span Full Exception ===" << std::endl;
    try
    {
        sp.addNumber(42);
        std::cout << "Added number 42" << std::endl;
    }
    catch (const SpanFullException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 3: Too Small Exception ===" << std::endl;
    Span smallSpan = Span(1);
    smallSpan.addNumber(42);
    
    try
    {
        unsigned int span = smallSpan.shortestSpan();
        std::cout << "Shortest span: " << span << std::endl;
    }
    catch (const SpanTooSmallException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 4: Empty Span Test ===" << std::endl;
    Span emptySpan = Span(10);
    
    try
    {
        unsigned int span = emptySpan.shortestSpan();
        std::cout << "Shortest span: " << span << std::endl;
    }
    catch (const SpanTooSmallException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 5: Large Span Test ===" << std::endl;
    Span largeSpan = Span(10000);
    
    for (int i = 0; i < 10000; i++)
    {
        largeSpan.addNumber(i);
    }
    
    std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
    
    std::cout << "\n=== Test 6: addNumbers with Iterator Range ===" << std::endl;
    Span rangeSpan = Span(10000);
    
    std::vector<int> numbers;
    for (int i = 0; i < 10000; i++)
        numbers.push_back(i * 2);
    
    rangeSpan.addNumbers(numbers.begin(), numbers.end());
    
    std::cout << "Added " << rangeSpan.getCurrentSize() << " numbers using iterator range" << std::endl;
    std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << rangeSpan.longestSpan() << std::endl;
    
    std::cout << "\n=== Test 7: addNumbers Exception Test ===" << std::endl;
    Span tinySpan = Span(5);
    std::vector<int> tooMany;
    for (int i = 0; i < 10; i++)
        tooMany.push_back(i);
    
    try
    {
        tinySpan.addNumbers(tooMany.begin(), tooMany.end());  // 10 > 5!
        std::cout << "Added all numbers" << std::endl;
    }
    catch (const SpanFullException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
        std::cout << "Successfully added: " << tinySpan.getCurrentSize() << " numbers" << std::endl;
    }
    
    return 0;
}
