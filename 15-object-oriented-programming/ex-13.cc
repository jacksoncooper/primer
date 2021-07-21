#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

class base
{
    public:

    base() = default;
    base(string name) : base_name(name) { }
    
    virtual void print(ostream &stream) {
        stream << base_name;
    }

    private:

    string base_name;
};

class derived : public base
{
    public:

    derived() = default;
    derived(string name, int integer) : base(name), integer(integer) { }

    void print(ostream &stream) {
        base::print(stream);
        stream << " " << integer;
    }

    private:

    int integer = 0;
};

int main()
{
    base my_base("four");
    my_base.print(cout);
    cout << endl;

    derived my_derived("three", 3);
    my_derived.print(cout);
    cout << endl;
}
