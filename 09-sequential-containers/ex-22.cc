#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    // Lots of issues.

    //  - The middle and finger iterators are invalidated when the vector is
    //    resized.
    //  - The finger iterator needs to progress through the numbers.

    const int some_number = 1;

    vector<int> numbers = { 1, 2, 3, 1, 4, 5, 1 };

    vector<int>::iterator
        finger = numbers.begin(),
        middle = numbers.begin() + numbers.size() / 2;

    vector<int>::difference_type to_middle = middle - numbers.begin();

    int insertions = 0;

    while (finger != numbers.begin() + to_middle + insertions)
    {
        if (*finger == some_number)
        {
            finger = numbers.insert(finger, 2 * some_number), ++finger;
            ++insertions;
        }
        ++finger;
    }

    for (int number : numbers) cout << number << " ";
    cout << endl;

    // input:    { 1, 2, 3, 1, 4, 5, 1 }
    //                      ^ mid

    // expect:   { 2, 1, 2, 3, 1, 4, 5, 1 }
};
