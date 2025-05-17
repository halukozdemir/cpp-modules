#include "FragTrap.hpp"
#include <iostream>

int main()
{
    FragTrap f("Frank");
    f.attack("enemy");
    f.takeDamage(40);
    f.beRepaired(30);
    f.highFivesGuys();

    std::cout << f.getName() << " HP: " << f.getHitPoints() << ", EP: " << f.getEnergyPoints() << std::endl;

    return 0;
}