#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name(name)
{
    
}

Zombie::~Zombie()
{
    std::cout << name << ": destroyed" << std::endl;
}