#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using std::vector;

using std::fill_n;

int main()
{
    // b.
    
    vector<int> my_vector;
    my_vector.reserve(10);
    // my_vector.resize(10);
    fill_n(my_vector.begin(), 10, 1); // fill_n does not _insert_ elements!
    
    // But the iterator we pass to fill_n should blindly walk the 10 integers
    // we've reserved. Why does it stop?
    
    // begin() called on an empty vector is the same as end(). But that shouldn't
    // prevent fill_n from incrementing past end().

    if (my_vector.empty()) {
        cout << "my_vector has no elements!" << endl;
        return 0;
    }

    for (int element : my_vector) cout << element << " ";
    cout << endl;
}
