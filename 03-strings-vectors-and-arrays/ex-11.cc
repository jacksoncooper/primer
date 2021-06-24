#include <string>

using std::string;

int main()
{
    const string signage = "Keep out!";
    const char &character = signage[signage.size() - 1];
    // character = '.';
}
