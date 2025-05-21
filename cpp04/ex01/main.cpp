#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
int main()
{
    std::cout << "===Animal Array Test===" << std::endl;
    const int size = 10;
    Animal* animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();
    
    std::cout << std::endl << "===Deep Copy Test===" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->ideas[0] = "Chase the cat!";
    Dog copiedDog = originalDog;
    copiedDog.getBrain()->ideas[0] = "Sleep all day!";

    std::cout << "Original dog's idea: " << originalDog.getBrain()->ideas[0] << std::endl;
    std::cout << "Copied dog's idea: " << copiedDog.getBrain()->ideas[0] << std::endl;

    std::cout << std::endl << "===Deleting Animals===" << std::endl;
    for (int i = 0; i < size; i++)
        delete animals[i];

    return 0;
}
