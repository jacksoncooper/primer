#include <iostream>

int main()
{
    // 'a' is initialized to 3.
    // 'b' is initialized to 4.

    int a = 3, b = 4;

    // 'c' has type int and is initialized to 3.

    decltype(a) c = a;

    // The assignment in decltype() is not evaluated, but would yield a
    // reference to its left operand it if were. 'a' has type int, so 'd' is a
    // reference to int.

    decltype(a = b) d = a;

    std::cout
        << "a: " << a   // a: 3
        << ", b: " << b // b: 4
        << ", c: " << c // c: 3
        << ", d: " << d // d: 3
        << std::endl;
}
