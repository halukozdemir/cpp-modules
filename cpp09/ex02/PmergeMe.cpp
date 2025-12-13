#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{

}

bool PmergeMe::isValidNumber(const std::string& str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    long num = atol(str.c_str());
    if (num < 0 || num > 2147483647)
        return false;
    return true;
}

void PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if (!isValidNumber(arg))
            throw std::runtime_error("Error: Invalid Number: " + arg);
        int num = atoi(arg.c_str());
        _vectorData.push_back(num);
        _dequeData.push_back(num);
    }
    if (_vectorData.empty())
        throw std::runtime_error("Error: No Numbers Provided");
}

void PmergeMe::insertionSortVector(std::vector<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i], j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::insertionSortDeque(std::deque<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i], j = i - 1;

        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeVector(std::vector<int>& arr, int left, int mid, int right)
{
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (int p = 0; p < k; p++)
        arr[left + p] = temp[p];
}

void PmergeMe::mergeDeque(std::deque<int>& arr, int left, int mid, int right)
{
    std::deque<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (int p = 0; p < k; p++)
        arr[left + p] = temp[p];
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr)
{
    int n = arr.size();
    if (n <= 1)
        return;
    const int THRESHOLD = 10;
    for (int i = 0; i < n; i += THRESHOLD)
    {
        int right = std::min(i + THRESHOLD - 1, n - 1);
        insertionSortVector(arr, i, right);
    }
    for (int size = THRESHOLD; size < n; size *= 2)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1, right = std::min(left + 2 * size - 1, n - 1);
            if (mid < right)
                mergeVector(arr, left, mid, right);
        }
    }
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr)
{
    int n = arr.size();
    if (n <= 1)
        return;
    const int THRESHOLD = 10;
    for (int i = 0; i < n; i += THRESHOLD)
    {
        int right = std::min(i + THRESHOLD - 1, n - 1);
        insertionSortDeque(arr, i, right);
    }
    for (int size = THRESHOLD; size < n; size *= 2)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1, right = std::min(left + 2 * size - 1, n - 1);
            if (mid < right)
                mergeDeque(arr, left, mid, right);
        }
    }
}

void PmergeMe::run(int argc, char **argv)
{
    parseInput(argc, argv);
    std::cout << "Before: ";
    for (size_t i = 0; i < _vectorData.size() && i < 5; i++)
        std::cout << _vectorData[i] << " ";
    if (_vectorData.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;

    clock_t startVector = clock();
    mergeInsertSortVector(_vectorData);
    clock_t endVector = clock();
    double timeVector = (double)(endVector - startVector) / CLOCKS_PER_SEC * 1000000;

    clock_t startDeque = clock();
    mergeInsertSortDeque(_dequeData);
    clock_t endDeque = clock();
    double timeDeque = (double)(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    for (size_t i = 0; i < _vectorData.size() && i < 5; i++)
        std::cout << _vectorData[i] << " ";
    if (_vectorData.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vectorData.size() << " elements with std::vector : " << timeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeData.size() << " elements with std::deque : " << timeDeque << " us" << std::endl;
}