#include <iostream>

using std::cout;
using std::endl;

// The declaration
//   void print(const int ia[10])
// is equivalent to
//   void print(const int *ia)

// The expression statement
//   cout << ia[i] << endl;
// is equivalent to
// cout << *(ia + i) << endl;

void print(const int ia[10]) {
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}

int main()
{
    int things[10] = {};
    for (size_t i = 0; i < 10; ++i) {
        things[i] = i;
    }
    print(things);
}

// p. 219
