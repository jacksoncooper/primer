#include <cassert>
#include <iostream>
#include <stack>
#include <string>

using std::cout;
using std::endl;
using std::stack;
using std::string;

string &replace_parenthesized(string &expression)
{
    stack<string::value_type> replaced;
    
    unsigned open_parentheses = 0;

    for (string::value_type character : expression)
    {
        replaced.push(character);

        switch (character)
        {
            case '(':
                ++open_parentheses;
                break;
            case ')':
                while (replaced.top() != '(') replaced.pop();
                replaced.pop();
                replaced.push('_');
        }
    }
    
    expression.clear();

    while (not replaced.empty())
    {
        expression.insert(expression.begin(), replaced.top());
        replaced.pop();
    }

    return expression;
}

int main()
{
    string my_expression = "( (1 + 3) / 2 ) + 8 - (2 * 4)";
    cout << replace_parenthesized(my_expression) << endl;
}
