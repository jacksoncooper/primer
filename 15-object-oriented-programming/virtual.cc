#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class toy
{
    public:

    virtual void make_noise(ostream &);
};

inline void toy::make_noise(ostream &out_stream) {
    out_stream << "*generic toy noise*";
}

class squeaker : public toy
{
    public:

    void make_noise(ostream &) override;
};

inline void squeaker::make_noise(ostream &out_stream) {
    out_stream << "*squeak*";
}

int main()
{
    toy my_toy;
    cout << "generic toy goes: ";
    my_toy.make_noise(cout);
    cout << endl;

    // Derived-to-base conversion!

    squeaker dog_toy;
    cout << "dog toy goes: ";
    static_cast<toy>(dog_toy).make_noise(cout);
    cout << endl;

    // Dynamic and static types of the following reference differ, so we must
    // mark make_noise() as virtual to tell the compiler to add code to
    // determine which method to call at runtime.

    toy &reference_to_dog_toy = dog_toy;
    cout << "dog toy goes: ";
    reference_to_dog_toy.make_noise(cout);
    cout << endl;
}
