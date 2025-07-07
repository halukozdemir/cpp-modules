#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat b1("Alice", 42);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl;
        b1.decrementGrade();
        std::cout << "After decrement: " << b1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    try
    {
        Bureaucrat b2("Bob", 0);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b3("Charlie", 151);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    try
    {
        Bureaucrat b4("Daisy", 1);
        std::cout << b4 << std::endl;
        b4.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b5("Eve", 150);
        std::cout << b5 << std::endl;
        b5.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
} 
