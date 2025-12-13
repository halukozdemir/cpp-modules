#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _database;
        void loadDatabase(const std::string& filename);
        bool isValidDate(const std::string& date);
        bool isValidValue(float value);
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        float getExchangeRate(const std::string& date);
        void processLine(const std::string& line);
};

#endif