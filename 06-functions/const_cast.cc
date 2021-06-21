#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

const string &shorter(const string &left, const string &right)
{
    return left.size() <= right.size() ? left : right;
}

int main()
{
    string my_string = "hello";
    string my_other_string = "darkness";
    string &my_short_string = const_cast<string&>(shorter(my_string, my_other_string));
    my_short_string[1] = 'a';
    cout << my_short_string << endl;
}
