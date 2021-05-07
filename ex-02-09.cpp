#include <iostream>

int main()
{
    // The following statement is illegal. The initialization of 'input_value'
    // is not an expression.

    // std::cin >> int input_value;

    // Illegal. The floating-point literal has type double by default, which
    // will be truncted when assigned to an integer. List initialization
    // prevents this truncation at compile time.

    // int i = { 3.14 };

    // Illegal. A variable definition cannot contain two equal signs.

    // double salary = wage = 9999.99;

    // Legal.

    int i = 3.14;
}
