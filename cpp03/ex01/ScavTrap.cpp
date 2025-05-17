#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << _name << " copy constructed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << "ScavTrap " << _name << " assigned!" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destructed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints == 0 || _hitPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " has no energy or hit points left to attack!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
