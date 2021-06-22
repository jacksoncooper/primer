#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

typedef string type; // [1] Global declaration of the type alias type.

type initialize_value(); // [2] Global declaration of the function init_val.

class exercise
{
    public:

        typedef double type; // [3] Member declaration of the type alias type.

//      Resolves to [3].
//      vvvv
        type set_value(type value);

//      Resolve to [3].
//      vvvv
        type initialize_value() { return 1.25; };

    private:

        int value;
};

//        Resolves to [1] without scope operator.
//        vvvv                     vvvv Resolves to [3].
exercise::type exercise::set_value(type parameter)
{
    value = parameter + initialize_value();
    return value;
}

// ^^^
// Question. When is your function body compiled? Immediately following the
// declaration of your class members, along with the function bodies of the
// other member functions? Or along with the other names in the global scope?

int main()
{
    exercise my_exercise;
    cout << my_exercise.set_value(2.75) << endl;
};
