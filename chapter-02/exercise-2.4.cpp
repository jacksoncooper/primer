int main()
{
    // The first is a character literal of type char. The second is of type
    // wchar_t or 'wide character'. The third and fourth are string literals.
    // The third is an array of constant char and the fourth is an array of
    // constant wchar_t.
    'a', L'a', "a", L"a";

    // The first is an integer literal of type signed int, the second unsigned
    // int, the third signed long, the fourth unsigned long.
    // 012 = 1 * 8 + 2 = 10 in base 10, which fits into a signed int.
    // 0xC = 12 in base 10, which also fits into a signed int.
    10, 10u, 10L, 10uL, 012, 0xC;

    // The first is a floating-point literal of type double. The second of type
    // float. The third of type long double.
    3.14, 3.14f, 3.14L;

    // The first and second are the same as above. The third is a floating-point
    // literal of type double. The fourth is also a floating-point literal of
    // type double.
    10, 10u, 10., 10e-2;
}
