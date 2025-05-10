#include "Zombie.hpp"
#include <iostream>

Zombie::~Zombie()
{
    std::cout << name << ": destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(void) : name("")
{

}

void Zombie::setName(std::string name)
{
    this->name = name;
}
