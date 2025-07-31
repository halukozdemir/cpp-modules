#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cctype>
#include <string>
#include <cerrno>

static void printChar(double d)
{
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(d)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

static void printInt(double d)
{
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
}

static void printFloat(double d)
{
    std::cout << "float: " << static_cast<float>(d);
    if (!std::isnan(d) && !std::isinf(d) && d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

static void printDouble(double d)
{
    std::cout << "double: " << d;
    if (!std::isnan(d) && !std::isinf(d) && d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << std::endl;
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
	{
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        return;
    }
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
	{
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }
    if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
        char c = literal[0];
        printChar(c);
        printInt(c);
        printFloat(c);
        printDouble(c);
        return;
    }
    if (isIntLiteral(literal))
	{
        errno = 0;
        long l = std::strtol(literal.c_str(), NULL, 10);
        if (errno == ERANGE || l < INT_MIN || l > INT_MAX) {
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
            return ;
        }
        int i = static_cast<int>(l);
        printChar(i);
        printInt(i);
        printFloat(i);
        printDouble(i);
        return;
    }
    if (literal.length() > 1 && literal[literal.length() - 1] == 'f')
	{
        std::string floatPart = literal.substr(0, literal.length() - 1);
        char* end;
        errno = 0;
        float f = std::strtof(floatPart.c_str(), &end);
        if (*end == '\0' && errno != ERANGE)
		{
            printChar(f);
            printInt(f);
            printFloat(f);
            printDouble(f);
            return;
        }
    }
    char* end;
    errno = 0;
    double d = std::strtod(literal.c_str(), &end);
    if (*end != '\0' || errno == ERANGE)
    {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
        return;
    }
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

ScalarConverter::ScalarConverter()
{

}
ScalarConverter::ScalarConverter(const ScalarConverter&)
{

}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
    return *this;
}
ScalarConverter::~ScalarConverter()
{
    
}
