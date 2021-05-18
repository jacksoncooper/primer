#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

//  0  1  2  3  4
// [1, 2, 3, 4, 5]

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
       cout << numbers[i] + numbers[numbers.size() - i - 1] << " ";
    cout << endl;
}

