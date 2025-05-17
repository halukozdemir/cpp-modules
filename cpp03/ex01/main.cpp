#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    ScavTrap s("Serena");
    s.attack("enemy");
    s.takeDamage(30);
    s.beRepaired(20);
    s.guardGate();

    std::cout << s.getName() << " HP: " << s.getHitPoints() << ", EP: " << s.getEnergyPoints() << std::endl;

    return 0;
}
