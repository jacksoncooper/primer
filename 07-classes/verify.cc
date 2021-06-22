#include <string>

using std::string;

int height;

class screen
{
    public:

        typedef string::size_type pos;

        void set_height(pos);

        pos height = 0;
};

screen::pos verify(screen::pos);

void screen::set_height(pos var)
{
    height = verify(var);
}

screen::pos verify(screen::pos height)
{
    return height;
}

int main()
{
}
