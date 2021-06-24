#include <vector>

using std::vector;

class example
{
    // Not const integral type and can't be initialized in the class body.

    // static double rate = 6.5;

    static const int vec_size = 20; // <- Okay.

    // Ditto, not const integral type or constexpr of literal type.

    // static vector<double> vec(vec_size);
    
    static vector<double> vec; // <- To properly declare.
};

// double example::rate;
// static vector<double> vec;

vector<double> example::vec(vec_size); // <- To properly define.

int main()
{
}
