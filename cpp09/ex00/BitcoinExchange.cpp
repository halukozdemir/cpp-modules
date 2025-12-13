#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return ;
    }
    std::string line;
    std::getline(file, line);

    while(std::getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos != std::string::npos)
        {
            std::string date = line.substr(0, pos);
            std::string valueStr = line.substr(pos + 1);
            float value = static_cast<float>(atof(valueStr.c_str()));
            _database[date] = value;
        }
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue ;
        if (!isdigit(date[i]))
            return false;
    }
    
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(float value)
{
    return value >= 0 && value <= 1000;
}

float BitcoinExchange::getExchangeRate(const std::string& date)
{
    std::map<std::string, float>::iterator it = _database.find(date);

    if (it != _database.end())
        return it->second;

    it = _database.lower_bound(date);
    if (it == _database.begin())
        return 0;

    --it;
    return it->second;
}

void BitcoinExchange::processLine(const std::string& line)
{
    if (line.empty())
        return ;
    size_t pos = line.find(" | ");
    if (pos == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return ;
    }

    std::string date = line.substr(0, pos);
    std::string valueStr = line.substr(pos + 3);

    size_t start = date.find_first_not_of(" \t\n\r\v\f");
    size_t end = date.find_last_not_of(" \t\n\r\v\f");
    if (start != std::string::npos && end != std::string::npos)
        date = date.substr(start, end - start + 1);

    start = valueStr.find_first_not_of(" \t\n\r\v\f");
    end = valueStr.find_last_not_of(" \t\n\r\v\f");
    if (start != std::string::npos && end != std::string::npos)
        valueStr = valueStr.substr(start, end - start + 1);
    
    if (!isValidDate(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return ;
    }

    float value = static_cast<float>(atof(valueStr.c_str()));

    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return ;
    }

    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return ;
    }

    float rate = getExchangeRate(date);
    float result = value * rate;

    std::cout << date << " => " << value << " = " << result << std::endl;
}
