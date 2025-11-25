#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "=== TEST 1: MutantStack ===" << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    std::cout << "Iterator loop:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);
    
    std::cout << "\n=== TEST 2: std::list (comparison) ===" << std::endl;
    
    std::list<int> mlist;
    
    mlist.push_back(5);
    mlist.push_back(17);
    
    std::cout << "Back: " << mlist.back() << std::endl;
    
    mlist.pop_back();
    
    std::cout << "Size: " << mlist.size() << std::endl;
    
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    
    std::list<int>::iterator lit = mlist.begin();
    std::list<int>::iterator lite = mlist.end();
    
    ++lit;
    --lit;
    
    std::cout << "Iterator loop:" << std::endl;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    std::cout << "\n=== TEST 3: Const Iterator ===" << std::endl;
    const MutantStack<int> cmstack(mstack);
    MutantStack<int>::const_iterator cit = cmstack.begin();
    MutantStack<int>::const_iterator cite = cmstack.end();

    while (cit != cite)
    {
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;

    return 0;
}
