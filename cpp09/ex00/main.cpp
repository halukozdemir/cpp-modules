#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange btc;

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(inputFile, line);

    while (std::getline(inputFile, line))
    {
        btc.processLine(line);
    }

    inputFile.close();
    return 0;
}
