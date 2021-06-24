#include <iostream>

int main()
{
    int i = 0, &r = i;
    auto a = r;

    // Okay, 'a' has type int, because it is initialized to the object 'r'
    // refers to.

    // Should get:
    // 'a' after definition: 0
    // 'a' after initialization: 42

    std::cout << "'a' after definition: "<< a << std::endl;
    a = 42;
    std::cout << "'a' after assignment: "<< a << std::endl;

    const int ci = i, &cr = ci;
    auto b = ci;

    // Okay, 'b' has type int because the top-level const is dropped in its
    // definition when the base type is auto.

    // Should get:
    // 'b' after definition: 0
    // 'b' after initialization: 42

    std::cout << "'b' after definition: "<< b << std::endl;
    b = 42;
    std::cout << "'b' after assignment: "<< b << std::endl;

    auto c = cr;

    // 'cr' is a reference to const int. 'c' is initialized with the object 'cr'
    // is bound to, so 'c' has type int.

    // Should get:
    // 'c' after definition: 0
    // 'c' after initialization: 42

    std::cout << "'c' after definition: "<< c << std::endl;
    c = 42;
    std::cout << "'c' after assignment: "<< c << std::endl;

    auto d = &i;

    // 'd' is a pointer to int and cannot be assigned to an integer literal.

    // d = 42;

    auto e = &ci;

    // 'ci' has type const int, so 'e' is inferred to be a pointer to const int.
    // An assignment of 'e' to an integer literal will fail.

    // e = 42;

    auto &g = ci;

    // 'ci' has type const int, and 'g' is inferred to be a reference to const
    // int. We cannot rebind a reference, so the assignment below will fail.

    // g = 42;
}
