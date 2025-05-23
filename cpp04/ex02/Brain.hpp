#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        virtual ~Brain();
        std::string ideas[100];
};

#endif
