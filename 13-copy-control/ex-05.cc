#include <cassert>
#include <string>

class HasPointer
{
    public:

    HasPointer(const std::string &a_string = std::string())
        : pointer_to_string(new std::string(a_string)) { }

    HasPointer(const HasPointer &has_pointer) {
        pointer_to_string = new std::string(*has_pointer.pointer_to_string);
        integer = has_pointer.integer;
    }

    std::string *pointer_to_string;
    int integer = 0;
};

int main()
{
    std::string name = "Linus Baker";

    HasPointer linus(name);
    HasPointer another_linus(linus);

    assert(another_linus.pointer_to_string != linus.pointer_to_string);
    assert(*another_linus.pointer_to_string == *linus.pointer_to_string);

    assert(linus.integer == 0);
    assert(another_linus.integer == 0);
}
