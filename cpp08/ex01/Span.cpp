#include "Span.hpp"

Span::Span() : _numbers(), _maxSize(0)
{

}

Span::Span(unsigned int N) : _maxSize(N)
{

}

Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize)
{

}

Span::~Span()
{

}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw SpanFullException();
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw SpanTooSmallException();
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < sorted.size(); i++)
    {
        unsigned int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw SpanTooSmallException();
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    return sorted.back() - sorted.front();
}

unsigned int Span::getMaxSize() const
{
    return _maxSize;
}

unsigned int Span::getCurrentSize() const
{
    return _numbers.size();
}

const char* SpanFullException::what() const throw()
{
    return "Span is full!";
}

const char* SpanTooSmallException::what() const throw()
{
    return "Span has less than 2 elements!";
}
