#include <list>
#include <vector>

using std::list;
using std::vector;

int main()
{
    list<double> my_list = { 1.5, 2.5, 3.5, 4.5 };

    // vector<double> my_vector = my_list; <- Container types do not match.

    vector<double> my_vector(
        my_list.cbegin(),
        my_list.cend()
    );

    vector<int> my_second_vector = { 1, 2, 3, 4 };

    vector<double> my_third_vector(
        my_second_vector.cbegin(),
        my_second_vector.cend()
    );
}
