#include <cstddef>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    const size_t rows = 3;
    const size_t columns = 4;

    int ia[rows][columns] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
    };

    // Using a range-based for statement.

    for (const int (&integers)[4] : ia) {
        for (int integer : integers) {
            cout << integer << " ";
        }
        cout << endl;
    }

    // Using subscripts.

    for (size_t row = 0; row < rows; ++row) {
        for (size_t column = 0; column < columns; ++column) {
            cout << ia[row][column] << " ";
        }
        cout << endl;
    }

    // Using pointers.

    for (int (*row)[columns] = ia; row != ia + rows; ++row) {
        for (int *column = *row; column != *row + columns; ++column) {
            cout << *column << " ";
        }
        cout << endl;
    }
}
