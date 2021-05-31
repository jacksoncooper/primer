#include <iostream>
#include <string>

using std::cout;
using std::string;

// Array of 10 empty strings.

int sa[10];

// Array of 10 int objects, default initialized. The int objects are
// initialized to zero because they are defined outside of a function body.

int ia[10];

int main()
{
    // Array of 10 string objects, default initialized. string is not a
    // built-in type. It is a class type, which initializes objects with no
    // explicit initializer to the empty string.

    string as2[10];

    // Array of 10 int objects, default initialized and uninitialized because
    // the objects are of built-in type and are defined in a function body.

    int ia2[10];
}
