#include <cassert>
#include <string>

class HasPointer
{
    public:

    HasPointer(const std::string &a_string = std::string())
        : pointer_to_string(new std::string(a_string)) { }

    HasPointer(const HasPointer &another) {
        pointer_to_string = new std::string(*another.pointer_to_string);
        integer = another.integer;
    }

    ~HasPointer() {
        if (pointer_to_string) delete pointer_to_string;
    }

    HasPointer &operator=(const HasPointer &another) {
        // We allocate a copy of another's string pointer before freeing the
        // string pointer in this in case another is the same object pointed to
        // by this.

        auto new_string_pointer = new std::string(*another.pointer_to_string);

        if (pointer_to_string) delete pointer_to_string;

        this -> pointer_to_string = new_string_pointer;
        this -> integer = another.integer;

        return *this;
    }

    std::string *pointer_to_string;
    int integer = 0;
};

int main()
{
    std::string name = "Linus Baker";
    HasPointer linus(name);
    linus.integer = 27;

    HasPointer another_linus = linus;

    assert(another_linus.pointer_to_string != linus.pointer_to_string);
    assert(*another_linus.pointer_to_string == *linus.pointer_to_string);

    assert(another_linus.integer == 27);

    std::string another_name = "Julien Baker";

    HasPointer julien(another_name);
    julien.integer = 25;

    linus = julien;

    assert(linus.pointer_to_string != julien.pointer_to_string);
    assert(*linus.pointer_to_string == *julien.pointer_to_string);

    assert(linus.integer == 25);
}
