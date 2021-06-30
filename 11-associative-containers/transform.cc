#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::map;
using std::runtime_error;
using std::string;

typedef map<string, string> trans_map;

void word_transform(ifstream &, ifstream &);
trans_map build_map(ifstream &);
const string &transform(const string &, const trans_map &);

void word_transform(ifstream &map_file, ifstream &input)
{
    trans_map trans_map = build_map(map_file);
    string text;
    while (getline(input, text)) {
        istringstream stream(text);
        string word;
        bool first_word = true;
        while (stream >> word) {
            if (first_word) first_word = false;
            else cout << " ";
            cout << transform(word, trans_map);
        }
    cout << endl;
    }
}

trans_map build_map(ifstream &map_file)
{
    trans_map trans_map;
    string key, value;
    while (map_file >> key and getline(map_file, value))
        // if (value.size() > 1) trans_map[key] = value.substr(1);
        if (value.size() > 1) trans_map.insert({ key, value.substr(1) }); // [1]
        else throw runtime_error("no rule for " + key);
    return trans_map;
}

// [1] Exercise 35: map.insert() does not replace the map::value_type if the
//     given key is already in the map.

const string &transform(const string &word, const trans_map &trans_map) {
    trans_map::const_iterator map_it = trans_map.find(word);
    if (map_it not_eq trans_map.cend()) return map_it -> second;
    else return word;
}

int main(int argc, char *argv[])
{
    if (argc == 3) {
        ifstream map = ifstream(argv[1]), transcript = ifstream(argv[2]);
        word_transform(map, transcript);
    }
}
