#include <iostream>

// Exercise Section 2.3.2 (p. 56)

void exercise_2_21()
{
    int i = 0;

    // Invalid. Cannot assign the address of an object of type int to a pointer
    // of type double.

    // double *dp = &i;

    // Invalid. Cannot initialize a pointer of type int using an object of
    // type int. To create a null pointer, use: int *ip = 0;

    // int *ip = i;

    // Valid.

    int *p = &i;
}

int main()
{
    return 0;
}
