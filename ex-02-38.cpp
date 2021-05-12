int main()
{
    // 'auto' and 'decltype' deduce different types.

    const char cracker = 'a';                // :: const char
    auto another = cracker;                  // :: char
    decltype(cracker) yet_another = cracker; // :: const char

    another = 'b';

    // Error, 'yet_another' has type const char.
    // yet_another = 'b';

    // 'auto' and 'decltype' deduce the same type.

    char *soup = &another;         // :: pointer to char
    auto more = soup;              // :: pointer to char
    decltype(soup) finally = soup; // :: pointer to char
}
