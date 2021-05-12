#include <iostream>

/*

In the program below:

- 'i' has type const int.
- 'j' has type int because it is initialized with a const int.
- 'k' is a reference to a const int. The const on the base type does nothing
-  because references have top-level const by default. They cannot be rebound.
- 'p' is a pointer to a const int.
- 'j2' is a const int.
- 'k2' is a reference to a const int.

1. const int i = 42;
2. auto j = i;
3. const auto &k = i;
4. auto *p = &i;
5. const auto j2 = i, &k2 = i;

*/

int main()
{
    const int i = 42;

    // Error. 'i' has type const int.

    // i = i - 1;

    auto j = i;

    const int another = 21;

    // Okay. 'j' has type int.
    j = another;
    std::cout << "'j' after assignment: " << j << std::endl;

    const auto &k = i;

    // Error. 'k' is a reference to const int. When we use a reference on the
    // LHS of an assignment, we are changing the object the reference is bound
    // to.

    // k = k - 1;
    // k = another;

    auto *p = &i;

    // Error. 'p' is a pointer to const int. Okay to assign to 'p' though.

    // *p = another;
    p = &another;

    const auto j2 = i, &k2 = i;

    // Error. 'j' has type const int.

    // j2 = another;

    // Error. 'k2' is a reference to const int.

    // k2 = another;
}
