#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <deque>
#include <string>
#include <vector>

class PmergeMe {
private:
  std::vector<int> _vec;
  std::deque<int> _deq;
  double _vecTime;
  double _deqTime;
  bool isValidNumber(const std::string &str) const;
  std::vector<int> getJacobsthalSequence(int n) const;
  template <typename Container>
  void insertWithBinarySearch(Container &sorted, int value);
  template <typename Container> void mergeInsertSort(Container &arr);

public:
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  void parseAndSort(int argc, char **argv);
  void displayResults() const;
};

template <typename Container>
void PmergeMe::insertWithBinarySearch(Container &sorted, int value) {
  typename Container::iterator pos =
      std::lower_bound(sorted.begin(), sorted.end(), value);
  sorted.insert(pos, value);
}

template <typename Container> void PmergeMe::mergeInsertSort(Container &arr) {
  if (arr.size() <= 1)
    return;
  bool hasStraggler = (arr.size() % 2 != 0);
  int straggler = 0;
  if (hasStraggler) {
    straggler = arr.back();
    arr.pop_back();
  }
  std::vector<std::pair<int, int> > pairs;
  for (size_t i = 0; i < arr.size(); i += 2) {
    int larger = std::max(arr[i], arr[i + 1]);
    int smaller = std::min(arr[i], arr[i + 1]);
    pairs.push_back(std::make_pair(larger, smaller));
  }
  Container largers;
  for (size_t i = 0; i < pairs.size(); ++i)
    largers.push_back(pairs[i].first);
  mergeInsertSort(largers);
  Container smallers;
  for (size_t i = 0; i < largers.size(); ++i) {
    for (size_t j = 0; j < pairs.size(); ++j) {
      if (pairs[j].first == static_cast<int>(largers[i])) {
        smallers.push_back(pairs[j].second);
        pairs[j].first = -1;
        break;
      }
    }
  }
  Container result(largers.begin(), largers.end());
  if (!smallers.empty())
    result.insert(result.begin(), smallers[0]);
  if (smallers.size() > 1) {
    std::vector<int> insertOrder = getJacobsthalSequence(smallers.size() - 1);
    for (size_t i = 0; i < insertOrder.size(); ++i) {
      int idx = insertOrder[i] + 1;
      if (idx < static_cast<int>(smallers.size()))
        insertWithBinarySearch(result, smallers[idx]);
    }
  }
  if (hasStraggler)
    insertWithBinarySearch(result, straggler);
  arr = result;
}

#endif
