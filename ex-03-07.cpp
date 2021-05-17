#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

int main()
{
    string to_redact;
    getline(cin, to_redact);

    for (char &character : to_redact) {
        character = 'x';

    }

    cout << to_redact << endl;
}
