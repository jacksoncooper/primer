#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class ice_cream
{
    public:

    ice_cream(string a_cone, string a_flavor, string a_topping) :
        cone(a_cone), flavor(a_flavor), topping(a_topping) { the_works(); }
    
    ice_cream() :
        ice_cream("sugar", "chocolate", "a drizzle of fudge") { cant_decide(); }

    private:

    string cone;
    string flavor;
    string topping;

    void the_works() {
        cout << "I'd like a " << cone << " cone with " << flavor
             << " ice cream topped with " << topping << ".";
    }

    void cant_decide() {
        cout << " " << "The house special!";
    }
};

int main()
{
    cout << "Harold: ";
    ice_cream coffee("waffle", "coffee", "chocolate chips");
    cout << endl;

    cout << "Beth: ";
    ice_cream chocolate;
    cout << endl;
}
