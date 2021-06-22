// What would happen if we put the typedef of pos in the screen class as the
// last line in the class?

#include <string>

using std::string;

int height;

class screen
{
    public:

        typedef string::size_type pos;

        // Member declarations are compiled first. The pos type in the
        // declaration of dummy_function is seen before the declaration of the
        // type alias pos.

        // What are you?! says the compiler.
        //                  vvv
        void dummy_function(pos height) {
            cursor = width * height;
        }

    private:

        pos cursor = 0;
        pos height = 0, width = 0;

        // typedef string::size_type pos; <- No good!
};

int main()
{
}
