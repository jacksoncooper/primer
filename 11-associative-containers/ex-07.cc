#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

typedef map<string, vector<string>> families;

void add_family(families &families, string last_name, vector<string> children)
{
    families[last_name] = children;
}

void add_children(families &families, string last_name, vector<string> children)
{
    vector<string> &existing_children = families[last_name];

    existing_children.insert(
        existing_children.begin(),
        children.cbegin(),
        children.cend()
    );
}

int main()
{
    map<string, vector<string>> my_families;

    string parr_family = "Parr";
    vector<string> children = { "Violet", "Dash" };
    vector<string> new_children = { "Jack-Jack" };

    add_family(my_families, parr_family, children);
    add_children(my_families, parr_family, new_children);

    vector<string> all_children = my_families[parr_family];

    cout << "Children in the Parr family: " << endl;
    for (string &child : all_children) cout << "  - " << child << endl;
}
