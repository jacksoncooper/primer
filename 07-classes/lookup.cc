#include <iostream>

using std::cout;
using std::endl;

int main()
{
    char my_thing = 'w';

    // Another enclosing scope.
    {
        // Enclosing scope.
        {
            // Local scope. Compound statements form a scope.
            {
                cout << my_thing << endl;
            }
        }
    }
}
