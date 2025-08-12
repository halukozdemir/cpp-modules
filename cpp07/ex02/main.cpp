#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    // Test 1: Default constructor
    std::cout << "=== Test 1: Default constructor ===" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    
    // Test 2: Parameterized constructor
    std::cout << "\n=== Test 2: Parameterized constructor ===" << std::endl;
    Array<int> numbers(5);
    std::cout << "Numbers array size: " << numbers.size() << std::endl;
    
    // Test 3: Assignment and access
    std::cout << "\n=== Test 3: Assignment and access ===" << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 10;
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }
    
    // Test 4: Copy constructor and deep copy test
    std::cout << "\n=== Test 4: Copy constructor and deep copy ===" << std::endl;
    Array<int> copy = numbers;
    std::cout << "Copy array size: " << copy.size() << std::endl;
    for (unsigned int i = 0; i < copy.size(); i++) {
        std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
    }
    
    // Test 4.5: Deep copy verification
    std::cout << "\n=== Test 4.5: Deep copy verification ===" << std::endl;
    std::cout << "Modifying original array..." << std::endl;
    numbers[0] = 999;
    std::cout << "Original numbers[0] = " << numbers[0] << std::endl;
    std::cout << "Copy numbers[0] = " << copy[0] << std::endl;
    std::cout << "Deep copy works if these are different!" << std::endl;
    
    // Test 5: Assignment operator
    std::cout << "\n=== Test 5: Assignment operator ===" << std::endl;
    Array<int> assigned(3);
    assigned = numbers;
    std::cout << "Assigned array size: " << assigned.size() << std::endl;
    for (unsigned int i = 0; i < assigned.size(); i++) {
        std::cout << "assigned[" << i << "] = " << assigned[i] << std::endl;
    }
    
    // Test 6: String array
    std::cout << "\n=== Test 6: String array ===" << std::endl;
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "World";
    strings[2] = "C++";
    for (unsigned int i = 0; i < strings.size(); i++) {
        std::cout << "strings[" << i << "] = " << strings[i] << std::endl;
    }
    
    // Test 7: Exception handling (out of bounds)
    std::cout << "\n=== Test 7: Exception handling ===" << std::endl;
    try
    {
        std::cout << "Trying to access numbers[10]..." << std::endl;
        int value = numbers[10];  // This should throw an exception
        std::cout << "This should not be printed: " << value << std::endl;
    } catch (const std::exception& e)
    {
        std::cout << "Exception caught: Out of bounds access!" << std::endl;
    }
    
    return 0;
}
