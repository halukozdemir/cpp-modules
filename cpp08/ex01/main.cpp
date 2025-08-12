#include "Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // Test 1: Basic functionality
    std::cout << "=== Test 1: Basic Functionality ===" << std::endl;
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    
    // Test 2: Exception test - Span full
    std::cout << "\n=== Test 2: Span Full Exception ===" << std::endl;
    try
    {
        sp.addNumber(42);  // 6. eleman - span dolu!
        std::cout << "Added number 42" << std::endl;
    }
    catch (const SpanFullException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 3: Exception test - Too small for span
    std::cout << "\n=== Test 3: Too Small Exception ===" << std::endl;
    Span smallSpan = Span(1);
    smallSpan.addNumber(42);
    
    try
    {
        unsigned int span = smallSpan.shortestSpan();  // Tek eleman var!
        std::cout << "Shortest span: " << span << std::endl;
    }
    catch (const SpanTooSmallException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 4: Empty span test
    std::cout << "\n=== Test 4: Empty Span Test ===" << std::endl;
    Span emptySpan = Span(10);
    
    try
    {
        unsigned int span = emptySpan.shortestSpan();  // Hiç eleman yok!
        std::cout << "Shortest span: " << span << std::endl;
    }
    catch (const SpanTooSmallException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 5: Large span test
    std::cout << "\n=== Test 5: Large Span Test ===" << std::endl;
    Span largeSpan = Span(10000);
    
    for (int i = 0; i < 10000; i++)
    {
        largeSpan.addNumber(i);
    }
    
    std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
    
    return 0;
}
