#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    // Geçerli bir Bureaucrat
    try {
        Bureaucrat b1("Alice", 42);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl;
        b1.decrementGrade();
        std::cout << "After decrement: " << b1 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    // Geçersiz derecelerle Bureaucrat oluşturma
    try {
        Bureaucrat b2("Bob", 0); // Çok yüksek derece
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 151); // Çok düşük derece
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    // Sınırda increment/decrement testleri
    try {
        Bureaucrat b4("Daisy", 1);
        std::cout << b4 << std::endl;
        b4.incrementGrade(); // Exception bekleniyor
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b5("Eve", 150);
        std::cout << b5 << std::endl;
        b5.decrementGrade(); // Exception bekleniyor
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
} 