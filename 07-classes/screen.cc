#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::vector;

class window_manager;

class screen
{
    public:

        typedef string::size_type pos;

        screen() = default;

        screen(pos ht, pos wd, char c = ' ')
            : height(ht), width(wd), contents(ht * wd, c) { }

        char get() const { return contents[cursor]; }
        inline char get(pos, pos) const;

        screen &set(char);
        screen &set(pos, pos, char);

        screen &mov(pos r, pos c);

        screen &display(ostream &os) { do_display(os); return *this; }
        const screen &display(ostream &os) const { do_display(os); return *this; }

    private:

        void do_display(ostream &) const;

    private:

        pos cursor = 0;
        pos height = 0, width = 0;
        string contents;

    friend window_manager;
};

class window_manager
{
    private:

        vector<screen> screens = { screen(24, 48, ' ') };
};

inline screen &screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline screen &screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}

char screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

inline screen &screen::mov(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

void screen::do_display(ostream &os) const
{
    for (pos pseudo_cursor = 0; pseudo_cursor < contents.size(); ++pseudo_cursor) {
        if (pseudo_cursor != 0 and pseudo_cursor % width == 0) {
            os << endl;
        }
        os << contents[pseudo_cursor];
    }
}

int main()
{
    screen my_screen(4, 8, '_');
    const screen my_blank_screen(4, 8, '_');

    my_screen.set('#').display(cout);
    cout << endl;

    cout << endl;

    my_blank_screen.display(cout);
    cout << endl;

    cout << endl;

    screen twenty_seven = screen(5, 5, '_');
    twenty_seven.mov(4, 0).set('#').display(cout);
    cout << endl;

    cout << endl;

    twenty_seven.display(cout);
    cout << endl;
}
