#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::istream;

istream &muck_with_stream(istream &stream)
{
    unsigned not_text;
    while (stream >> not_text) cout << not_text << endl;
    // stream.clear(stream.rdstate() & ~istream::failbit & ~istream::eofbit);
    stream.clear();
    return stream;
}

int main()
{
    // Why doesn't this let me muck twice? istream::failbit should be reset by
    // the call to clear().

    muck_with_stream(muck_with_stream(cin)); 

    cout << "All done." << endl;
}
