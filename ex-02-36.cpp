#include <iostream>

int main()
{
    // 'a' is initialized to 3.
    // 'b' is initialized to 4.

    int a = 3, b = 4;

    // 'a' has type int, so 'c' has type int. 'c' is initialized to 3.

    decltype(a) c = a;

    // '(b)' is an expression that evaluates to a variable, which can be used in
    // the LHS of an assignment. So decltype() returns a reference type, and
    // 'd' is a reference to int. 'd' is bound to 'a'.

    decltype((b)) d = a;

    // 'c' is incremented to 4.

    ++c;

    // 'a' is incremented to 4.

    ++d;

    std::cout
        << "a: " << a   // a: 4
        << ", b: " << b // b: 4
        << ", c: " << c // c: 4
        << ", d: " << d // d: 4
        << std::endl;
}
