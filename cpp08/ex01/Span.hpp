#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <climits>

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
        template<typename Iterator>
        void addNumbers(Iterator begin, Iterator end);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        unsigned int getMaxSize() const;
        unsigned int getCurrentSize() const;
};

template<typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
    while (begin != end)
    {
        if (_numbers.size() >= _maxSize)
            throw SpanFullException();
        _numbers.push_back(*begin);
        ++begin;
    }
}

#endif
