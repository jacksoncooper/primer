#include <iostream>

// Exercise Section 2.4.2 (p. 64)

void exercise_2_27()
{
    // (a) int i = -1, &r = 0;

    // Illegal. The reference 'r' is bound to a literal.

    // (b) int *const p2 = &i2;

    // Legal, if 'i2' has type int.

    // (c) const int i = -1, &r = 0;

    // Legal. 'r' is a reference to a constant object of type int.

    // Equivalent to

    // const int i = -1;
    // const int temp = 0;
    // const int &r = temp;

    // (d) const int *const p3 = &i2;

    // Legal, if 'i2' has type int or const int.

    // (e) const int *p1 = &i2;

    // Legal, if 'i2' has type int or const int.

    // (f) const int &const r2;

    // Illegal. References to constant have the base type 'const _'. References
    // are constant by default; they cannot be bound to different objects. The
    // constant following the ampersand is exclusive to pointers.

    // (g) const int i2 = i, &r = i;

    // Legal.
}

void exercise_2_28()
{
    // (a) int i, *const cp;

    // Illegal. 'cp' is a constant pointer and must be initialized.

    // (b) int *p1, *const p2;

    // Illegal, for the same reason as (a).

    // (c) const int ic, &r = ic;

    // Illegal. 'ic' has type constant int and must be initialized. 'r' is a
    // reference to an object that has type const int, which is okay.

    // (d) const int *const p3;

    // Illegal. This is a constant pointer which must be initialized.

    // (e) const int *p;

    // Legal. 'p' is a pointer to an object that has type const int.
}

void exercise_2_29()
{
    // (a) i = ic;

    // Legal. 'i' has type int and 'ic' has type const int. The value of 'ic'
    // is copied to 'i'.

    // (b) p1 = p3;

    // Illegal. 'p1' has type pointer to int and 'p3' has type constant pointer
    // to const int. 'p1' cannot point to const int.

    // (c) p1 = &ic;

    // 'ic' has type const int. 'p1' has type pointer to int. This is illegal
    // because 'p1' cannot point to const int.

    // (d) p3 = &ic;

    // 'p3' has type constant pointer to const int and 'ic' has type const int.
    // This is okay. The pointer to const int can point to a const int.

    // (e) p2 = p1;

    // 'p2' has type constant pointer to int and 'p1' has type pointer to int.
    // This is okay. The int address in 'p1' is copied to 'p2'.

    // (f) ic = *p3;

    // 'ic' has type const int. 'p3' has type constant pointer to const int.
    // Dereferencing 'p3' yields a const int, which can be copied to an object
    // that has type const int. This is okay.
}

int main()
{
    return 0;
}
