#include <iostream>
#include <string>
#include "iter.hpp"

/* 테스트용 함수 템플릿 */
template <typename T>
void print(T const& x)
{
    std::cout << x << std::endl;
}

/* 수정하는 함수 */
void increment(int& x)
{
    ++x;
}

/* 반환값이 있는 callable */
int square(int x)
{
    return x * x;
}

int main(void)
{
    std::cout << "=== 기본 동작 테스트 ===" << std::endl;
    int a[] = {1, 2, 3};
    iter(a, 3, print<int>);

    std::cout << "\n=== 다른 타입 테스트 ===" << std::endl;
    std::string s[] = {"hello", "world"};
    iter(s, 2, print<std::string>);

    std::cout << "\n=== length = 0 테스트 ===" << std::endl;
    iter(a, 0, print<int>);  // 아무 것도 출력 안 되어야 함

    std::cout << "\n=== 원소 수정 함수 테스트 ===" << std::endl;
    iter(a, 3, increment);
    iter(a, 3, print<int>);

    std::cout << "\n=== 반환값이 있는 함수 테스트 ===" << std::endl;
    iter(a, 3, square);  // 반환값은 무시됨 (컴파일은 됨)

    std::cout << "\n=== const 배열 테스트 (컴파일 에러 기대) ===" << std::endl;
    const int c[] = {10, 20, 30};
    iter(c, 3, print<int>); // ❌ 컴파일 에러 발생

    return 0;
}
