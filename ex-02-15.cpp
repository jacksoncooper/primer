#include <iostream>

// Exercise Section 2.3.1 (p. 51)

void exercise_2_15()
{
    int ival = 1.01;

    // Invalid. References may not be bound to literals.

    // int &rval1 = 1.01;

    // Valid. 'rval2' is a reference to the object 'ival' of type int. The type
    // of the reference and the type of the referenced object match.

    int &rval2 = ival;

    // Invalid. References require an initializer.

    // int &rval3;
}

void exercise_2_16()
{
    int i = 0, &r1 = i; double d = 0, &r2 = d;

    // Valid. Assigns the floating-point literal 3.14159 of type double to the
    // object referred to by 'r2', i.e., the variable 'd' also of type double.

    // d = 3.14159

    r2 = 3.14159;

    std::cout << r2 << ", ";

    // Valid. Assigns the object of type int referred to by 'r1' to the object
    // of type double referred to by r2.

    // d = 0

    r2 = r1;

    std::cout << r2 << ", ";

    // Valid. The object referred to by 'r2' is a double, so it is truncated on
    // assignment an object of type int.

    // i = 0

    i = r2;

    std::cout << i << ", ";

    // Valid.

    // i = 0

    r1 = d;

    std::cout << r1 << std::endl;
}

void exercise_2_17()
{
    // Assuming 'i' below was intended to be default initialized to 0 in the
    // global scope.

    //int i, &ri = i;

    int i = 0, &ri = i;

    // i = 0

    i = 5; ri = 10;

    // i = 10

    std::cout << i << " " << ri << std::endl; // 10 10
}

int main()
{
    return 0;
}
