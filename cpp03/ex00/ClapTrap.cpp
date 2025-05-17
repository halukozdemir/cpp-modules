#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) : _name(clapTrap._name), _hitPoints(clapTrap._hitPoints), _energyPoints(clapTrap._energyPoints), _attackDamage(clapTrap._attackDamage)
{
    std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
    if (this != &clapTrap)
    {
        _name = clapTrap._name;
        _hitPoints = clapTrap._hitPoints;
        _energyPoints = clapTrap._energyPoints;
        _attackDamage = clapTrap._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints == 0 || _hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy or hit points left to attack!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    if (amount >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints == 0 || _hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " can't be repaired (no energy or hit points)!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
    _hitPoints += amount;
    _energyPoints--;
}
