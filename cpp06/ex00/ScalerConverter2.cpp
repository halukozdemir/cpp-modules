#include "ScalarConverter.hpp"

static void printFloat(double d)
{
    std::cout << "float: " << static_cast<float>(d);
    if (!std::isnan(d) && !std::isinf(d) && d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

static bool isIntLiteral(const std::string& s)
{
    if (s.empty())
        return false;
    size_t i = 0;
    if (s[i] == '-' || s[i] == '+')
        i++;
    if (i == s.length())
        return false;
    for (; i < s.length(); ++i)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

void ScalarConverter::convert(const std::string& literal)
{
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
}