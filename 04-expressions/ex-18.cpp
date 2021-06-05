#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> my_stuff = {1, 2, 3, 4, 5, 6};
    vector<int>::const_iterator finger = my_stuff.begin();

    // The prefix increment operator has the same precedence as the dereference
    // operator and is right-associative. So

    // *++finger
    // *(++finger)
    // *(finger + 1)

    // This dereferences the element to the right of finger so we will end up
    // dereferencing the off-the-end pointer, which is undefined behavior. My
    // compiler simply yields zero.

    while (finger != my_stuff.end() and *finger >= 0) {
        cout << *++finger << " ";
    }

    cout << endl;
}
