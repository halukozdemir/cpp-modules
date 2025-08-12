#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <climits>

class Span
{
    private:
        std::vector<int> _numbers;
        unsigned int _maxSize;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        ~Span();
        Span& operator=(const Span& other);
        void addNumber(int number);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        unsigned int getMaxSize() const;
        unsigned int getCurrentSize() const;
};

class SpanFullException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class SpanTooSmallException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

#endif
