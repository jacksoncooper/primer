#include <string>
#include <vector>

using std::string;
using std::vector;

int main()
{
    // Legal. Default initialize a vector of vectors with integer elements.

    vector<vector<int>> ivec;

    // Illegal. Cannot copy initialize a vector with string elements from a
    // vector with integer elements.

    // vector<string> svec = ivec;

    // Legal. Direct initialize a vector with 10 string elements, all "null".

    vector<string> svec(10, "null");
}
