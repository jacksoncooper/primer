#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int poor_integer = 6;

    auto decrement = [&poor_integer] ()
        { return poor_integer ? --poor_integer, false : true; };

    int bludgeons = 10;

    cout << "poor_integer = " << poor_integer << endl;

    while (bludgeons > 0) {
        bool dead = decrement();
        cout << "poor_integer = " << poor_integer
             << "; dead? " << dead << endl;
        --bludgeons;
    }
}
