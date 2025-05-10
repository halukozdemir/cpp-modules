#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;



    std::cout << std::setw(39) << "Memory address of the string variable: " << &str << std::endl;
    std::cout << std::setw(39) << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << std::setw(39) << "Memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << std::setw(39) << "Value of the string variable: " << str << std::endl;
    std::cout << std::setw(39) << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << std::setw(39) << "Value pointed to by stringREF: " << stringREF <<  std::endl;

    return 0;
}
