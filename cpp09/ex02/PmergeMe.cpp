#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>
#include <iostream>

PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
    : _vec(other._vec), _deq(other._deq), _vecTime(other._vecTime),
      _deqTime(other._deqTime) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    _vec = other._vec;
    _deq = other._deq;
    _vecTime = other._vecTime;
    _deqTime = other._deqTime;
  }
  return *this;
}
PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const std::string &str) const {
  if (str.empty())
    return false;
  for (size_t i = 0; i < str.length(); ++i) {
    if (!std::isdigit(str[i]))
      return false;
  }
  return true;
}

std::vector<int> PmergeMe::getJacobsthalSequence(int n) const {
  std::vector<int> jacobsthal;
  std::vector<int> result;

  jacobsthal.push_back(0);
  jacobsthal.push_back(1);
  while (jacobsthal.back() < n) {
    int next = jacobsthal[jacobsthal.size() - 1] +
               2 * jacobsthal[jacobsthal.size() - 2];
    jacobsthal.push_back(next);
  }
  std::vector<bool> used(n, false);
  for (size_t i = 1; i < jacobsthal.size() && jacobsthal[i] <= n; ++i) {
    int current = jacobsthal[i];
    for (int j = current; j > jacobsthal[i - 1]; --j) {
      if (j - 1 < n && !used[j - 1]) {
        result.push_back(j - 1);
        used[j - 1] = true;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (!used[i])
      result.push_back(i);
  }
  return result;
}

void PmergeMe::parseAndSort(int argc, char **argv) {
  if (argc < 2)
    throw std::runtime_error("Error: no input provided.");
  for (int i = 1; i < argc; ++i) {
    std::string arg(argv[i]);
    if (!isValidNumber(arg))
      throw std::runtime_error("Error: invalid input '" + arg + "'.");
    long num = std::atol(argv[i]);
    if (num <= 0 || num > INT_MAX)
      throw std::runtime_error("Error: invalid input '" + arg + "'.");
    _vec.push_back(num);
    _deq.push_back(num);
  }
  std::cout << "Before: ";
  for (size_t i = 0; i < _vec.size(); ++i) {
    std::cout << _vec[i];
    if (i < _vec.size() - 1)
      std::cout << " ";
  }
  std::cout << "\n";
  std::clock_t start = std::clock();
  mergeInsertSort(_vec);
  std::clock_t end = std::clock();
  _vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
  start = std::clock();
  mergeInsertSort(_deq);
  end = std::clock();
  _deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::displayResults() const {
  std::cout << "After:  ";
  for (size_t i = 0; i < _vec.size(); ++i) {
    std::cout << _vec[i];
    if (i < _vec.size() - 1)
      std::cout << " ";
  }
  std::cout << std::endl;
  std::cout << "Time to process a range of " << _vec.size()
            << " elements with std::vector : " << _vecTime << " us"
            << std::endl;
  std::cout << "Time to process a range of " << _deq.size()
            << " elements with std::deque  : " << _deqTime << " us"
            << std::endl;
}