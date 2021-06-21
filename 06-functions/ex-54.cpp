#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int binary(int, int);

typedef decltype(binary) binary_function;

int add(int left, int right)
{
    return left + right;
}

int subtract(int left, int right)
{
    return left - right;
}

int main()
{
    vector<binary_function*> functions = { &add, &subtract };

    for (binary_function* function : functions)
        cout << function(4, 2) << endl;
}
