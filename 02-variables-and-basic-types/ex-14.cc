#include <iostream>

int main()
{
    int i = 100, sum = 0;

    for (int i = 0; i not_eq 10; ++i)
        sum += i;

    // The identifier 'i' is plucked from its outer scope, because the other
    // 'i' is defined in the scope of the for statement.

    // 100 (0 + 1 + ... + 9 = 45)

    std::cout << i << " " << sum << std::endl;
}
