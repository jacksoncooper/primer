#include <iostream>
#include <iterator>

using std::cout;
using std::end;
using std::endl;

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    int *p1 = numbers; // = &numbers[0];
    int *p2 = end(numbers) - 1;

    // Moves the pointer p1 to p2. p2 - p1 is the distance between p2 and p1,
    // i.e, the number of hops p1 must take to arrive at p2. This integer can
    // be positive or negative and has type ptrdiff_t.

    cout << "p1 points to " << *p1 << "." << endl;

    p1 += p2 - p1;

    cout << "p1 now points to " << *p1 << "." << endl;
}
