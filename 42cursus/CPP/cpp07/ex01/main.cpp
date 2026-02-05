#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const& x)
{
    std::cout << x << std::endl;
}

template <typename T>
void increment(T& x)
{
    ++x;
}

int main(void)
{
    std::cout << "=== int array iter ===" << std::endl;
    int a[] = {1, 2, 3};
    iter(a, 3, print<int>);

    std::cout << "\n=== string array iter ===" << std::endl;
    std::string s[] = {"hello", "world"};
    iter(s, 2, print<std::string>);

    std::cout << "\n=== testing with 0 length ===" << std::endl;
    iter(a, 0, print<int>);  // should print nothing

    std::cout << "\n=== incremeting func call ===" << std::endl;
    iter(a, 3, increment<int>);
    iter(a, 3, print<int>);

    std::cout << "\n=== exceeding index testing ===" << std::endl;
    const int c[] = {10, 20, 30};
    iter(c, 5, print<int>); // printing dummy data. possible segmentation fault

    std::cout << "\n=== error case testing ===" << std::endl;
    // iter(c, 3, increment<int>); // compile failure

    return 0;
}
