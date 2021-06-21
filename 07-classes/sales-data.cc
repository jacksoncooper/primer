#include <iostream>
#include <string>

using std::istream;
using std::ostream;

using std::cin;
using std::cout;
using std::endl;

using std::string;

class sales_data {
    // Constructors.

    public:

        sales_data();
        sales_data(const string &);
        sales_data(const string &, unsigned, double);
        sales_data(istream &);

    // Data members.
   
    private:

        string book_number;
        unsigned units_sold = 0;
        double revenue = 0;

    // Member functions.

    public:

        // isbn() implicitly accesses the book_number member of the object on
        // which isbn() is called.
        //                           vvvvvvvvvvv
        string isbn() const { return book_number; }
        sales_data &combine(const sales_data &);

    private:

        double average_price() const;

    // Friendship not affected by access specifiers.

    friend sales_data add(const sales_data &, const sales_data &);
    friend ostream &print(ostream &, const sales_data &);
    friend istream &read(istream &, sales_data &);
};

// Ordinarily nonmember functions that are part of the interface of a class
// should be declared in the same header as the class itself.

sales_data add(const sales_data &sale, const sales_data &other) {
    sales_data sum = sale;
    sum.combine(other);
    return sum;
}

ostream &print(ostream &stream, const sales_data &sale) {
    stream << sale.isbn() << " "
           << sale.units_sold << " "
           << sale.revenue << " "
           << sale.average_price();
    return stream;
}

istream &read(istream &stream, sales_data &sale) {
    double price = 0;
    stream >> sale.book_number >> sale.units_sold >> price;
    sale.revenue = price * sale.units_sold;
    return stream;
}

// Member functions that are not defined inline.

sales_data::sales_data() = default;

sales_data::sales_data(const string &book_number) {
    this -> book_number = book_number;
}

sales_data::sales_data(
    const string &book_number,
    unsigned units_sold,
    double price
) : book_number(book_number),
    units_sold(units_sold),
    revenue(units_sold * price) { };

sales_data::sales_data(istream &stream) {
    read(stream, *this);
}

double sales_data::average_price() const {
    if (units_sold) return revenue / units_sold;
    else return 0;
}

sales_data &sales_data::combine(const sales_data &other) {
    units_sold += other.units_sold;
    revenue += other.revenue;
    return *this;
}

int main() {
    string book_number = "0-321-71411-3";
    unsigned units_sold = 12;
    double price_per_copy = 69.99;

    sales_data my_sale(book_number, units_sold, price_per_copy);

    print(cout, my_sale);

    cout << endl;
}
