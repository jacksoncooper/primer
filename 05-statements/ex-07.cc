#include <iostream>

using std::cout;
using std::endl;

int get_value() {
    return 0;
}

int main()
{
    // a.
    {
        int ival1 = 0, ival2 = 0;

        if (ival1 != ival2)
            ival1 = ival2; // <- Missing semicolon, not an expression statement.
        else ival1 = ival2 = 0;
    }

    // b.
    {
        int ival = 0, minval = 0, occurs = 0;

        if (ival < minval) { // <- Missing compound statement in if body.
            minval = ival;
            occurs = 1;
        }
    }

    // c.
    {
        int ival = 0; // <- Can't access 'ival' outside the scope of the first if.
        if ((ival = get_value()))
            cout << "ival = " << ival << endl;
        if (!ival)
            cout << "ival = 0\n";
    }

    // d.
    {
        int ival = 0;
        if (ival == 0) // <- The condition (ival = 0) will never execute.
            ival = get_value();
    }
}
