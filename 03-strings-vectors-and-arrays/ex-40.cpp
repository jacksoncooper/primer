#include <cstring>
#include <cstddef>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    const char text[] = "func";
    const char more_text[] = "tion";

    const size_t together_length = strlen(text) + strlen(more_text) + 1;
    char together[together_length] = {};

    strcpy(together, text);
    strcat(together, more_text);

    cout << together << endl;
}
