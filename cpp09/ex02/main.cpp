#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe <numbers...>" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe pmergeMe;
        pmergeMe.run(argc, argv);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}