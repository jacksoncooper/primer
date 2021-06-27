#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;

using std::end;
using std::begin;

using std::fill;

int main()
{
    int my_numbers[] = { 1, 2, 1, 2, 1, 2 };

    cout << "sizeof my_numbers: "
         <<  sizeof my_numbers << endl;
    cout << "sizeof *my_numbers: "
         <<  sizeof *my_numbers << endl;
    cout << "sizeof my_numbers / sizeof *my_numbers: "
         <<  sizeof my_numbers / sizeof *my_numbers << endl;
    //                                  ^
    // Why do you suddently have pointer type when I deference you?
    // You're an array of int.

    fill(begin(my_numbers), end(my_numbers), 0);

    cout << "my_numbers: ";
    for (int number: my_numbers) cout << number << " ";
    cout << endl;
}
