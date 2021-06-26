#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::string;
using std::vector;

vector<string> to_lines(istream &stream)
{
    string line;
    vector<string> lines;
    while (getline(stream, line)) lines.push_back(line);
    return lines;
}

int main(int argc, char *argv[])
{
    ifstream my_song(argv[1]);
    vector<string> my_lines = to_lines(my_song);
    for (string &line : my_lines) cout << line << endl;
}
