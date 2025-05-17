#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Alice");
    ClapTrap b("Bob");
    a.attack("Bob");
    b.takeDamage(3);
    b.beRepaired(2);

    return 0;
}
