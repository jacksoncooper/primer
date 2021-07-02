#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

// Exersie 27: Without looking ahead, write your own versions of the TextQuery
// and QueryResult classes.

class QueryResult;

class TextQuery
{
    friend QueryResult;

    public:

    TextQuery(std::ifstream &);

    QueryResult query(std::string &);

    private:

    typedef std::vector<std::string> text_type;
    typedef unsigned line_number_type;
    typedef std::set<line_number_type> line_numbers_type;
    typedef std::map<std::string, line_numbers_type> map_type;

    std::shared_ptr<text_type> lines = std::make_shared<text_type>();
    std::shared_ptr<map_type> word_to_lines = std::make_shared<map_type>();
};

class QueryResult
{
    friend std::ostream &print(std::ostream &, QueryResult &);

    public:

    QueryResult(TextQuery &, std::string);

    void print(std::ostream &);

    private:

    typedef TextQuery::line_number_type line_number_type;
    typedef TextQuery::line_numbers_type line_numbers_type; // Reexport? Yuck!

    std::string word;
    std::shared_ptr<TextQuery::text_type> lines;
    std::shared_ptr<TextQuery::map_type> word_to_lines;
};

TextQuery::TextQuery(std::ifstream &infile) {
    std::string line;
    unsigned line_number = 0;

    while(getline(infile, line)) {
        ++line_number;
        lines -> push_back(line);

        std::istringstream words(line);
        std::string word;

        while (words >> word) {
            (*word_to_lines)[word].insert(line_number); // Yuck!
        }
    };
}

QueryResult TextQuery::query(std::string &word) {
    return QueryResult(*this, word);
}

QueryResult::QueryResult(TextQuery &query, std::string word)
    : word(word), lines(query.lines), word_to_lines(query.word_to_lines) { };

std::ostream &print(std::ostream &ostream, QueryResult &result) {
    QueryResult::line_numbers_type lines = (*result.word_to_lines)[result.word];
    QueryResult::line_number_type times = lines.size();

    ostream << "'" << result.word << "' occurrs in "
            << times << " lines" << std::endl;

    for (unsigned line : lines) {
        ostream << "  (line " << line << ") "
                << (*result.lines)[line - 1] << std::endl;
    }

    return ostream;
}

void run_queries(std::ifstream &infile) {
    TextQuery *query = new TextQuery(infile);
    while (true) {
        std::cout << "Enter a word to look for, or 'q' to quit: ";
        std::string word;
        if (not (std::cin >> word) or word == "q") break;
        QueryResult result = query -> query(word);
        print(std::cout, result) << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::ifstream infile(argv[1]); // Danger!
    run_queries(infile);
}

