#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::count;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> my_integers;

    int looking_for = 0, an_integer = 0;

    while (cin >> an_integer) {
        if (not an_integer) break;
        my_integers.push_back(an_integer);
    }

    cin >> looking_for;

    int how_many = count(my_integers.cbegin(), my_integers.cend(), looking_for);

    cout << "I found " << how_many << " " << looking_for << "'s in your input." << endl;
}
