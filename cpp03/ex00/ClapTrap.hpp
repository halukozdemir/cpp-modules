#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
    public:
        ClapTrap(const std::string& name);
        ClapTrap();
        ~ClapTrap();
        ClapTrap(const ClapTrap& clapTrap);
        ClapTrap& operator=(const ClapTrap& clapTrap);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    private:
        std::string     _name;
        unsigned int    _hitPoints;
        unsigned int    _energyPoints;
        unsigned int    _attackDamage;
};

#endif
