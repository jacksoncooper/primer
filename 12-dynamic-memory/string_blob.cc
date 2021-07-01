#include <cassert>
#include <iostream>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StringBlob
{
    public:

    typedef std::vector<std::string>::size_type size_type;
    typedef std::initializer_list<std::string> initializers;
    typedef std::vector<std::string> items;

    StringBlob();
    explicit StringBlob(initializers);

    size_type size() const { return pointer -> size(); }

    bool empty() const { return pointer -> empty(); }

    void push_back(const std::string &a_string) {
        pointer -> push_back(a_string);
    }

    void pop_back();

    std::string &front();
    std::string &front() const;

    std::string &back();
    std::string &back() const;

    std::string &get_front() const;
    std::string &get_back() const;

    private:

    std::shared_ptr<items> pointer;

    void check(size_type index, const std::string &message) const;
};

StringBlob::StringBlob() :
    pointer(std::make_shared<items>()) { }

StringBlob::StringBlob(initializers strings) :
    pointer(std::make_shared<items>(strings)) { }

void StringBlob::pop_back() {
    check(0, "pop_back on empty Stringblob");
    return pointer -> pop_back();
}

// Exercise 2:

std::string &StringBlob::front() { return get_front(); }
std::string &StringBlob::front() const { return get_front(); }

std::string &StringBlob::back() { return get_front(); }
std::string &StringBlob::back() const { return get_front(); }

std::string &StringBlob::get_front() const {
    check(0, "front on empty StringBlob");
    return pointer -> front();
}

std::string &StringBlob::get_back() const {
    check(0, "back on empty StringBlob");
    return pointer -> back();
}

// Exercise 3: No. push_back() and pop_back() mutate their implicit argument and
// cannot accept pointers to constant StringBlob's.

void StringBlob::check(size_type index, const std::string &message) const {
    if (index >= pointer -> size()) throw std::out_of_range(message);
}
    
int main()
{
    // Exercise 1: How many elements do one and another have at the end of this
    // code?

    StringBlob one;
    {
        StringBlob another({"a", "an", "the" });
        // another's shared pointer copied to one. 
        one = another;
        another.push_back("about");
        assert(another.size() == 4);
    }

    assert(one.size() == 4);
}
