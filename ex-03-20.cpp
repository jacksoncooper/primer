#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

//  0  1  2  3  4
//  4  3  2  1  0
// [1, 2, 3, 4, 5]

// 0 + (l - 1 - 0) = l - 1 -> 4
// 1 + (l - 1 - 2) = l - 2 -> 3
// 2 + (l - 1 - 4) = l - 3 -> 2
// 3 + (l - 1 - 6) = l - 4 -> 1
// 4 + (l - 1 - 8) = l - 5 -> 0

// Expect:
// 3 5 7 9
// 6 6

int main()
{
    unsigned number;
    vector<unsigned> numbers;

    while (cin >> number) {
        numbers.push_back(number);
    }

    // Does auto infer i :: vector<unsigned>::size_type?

    for (auto i = 0; i < numbers.size() - 1; ++i)
        cout << numbers[i] + numbers[i + 1] << " ";
    cout << endl;

    // Ignores middle element of vector of odd length.

    for (auto i = 0; i < numbers.size() / 2; ++i)
       cout << numbers[i] + numbers[numbers.size() - 1 - i] << " ";
    cout << endl;
}

