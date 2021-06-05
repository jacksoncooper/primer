int txt_size()
{
    return 32;
}

int main()
{
    unsigned buf_size = 1024;

    // Should be illegal because buf_size is not a constant expression; its
    // value can change. Still compiles for mysterious reasons.

    int one[buf_size];

    // Legal.

    int two[4 * 7 - 14];

    // Legal. text_size() is known at compile time.

    int three[txt_size()];

    // Illegal. The string literal used to initialize the array includes the
    // null character. The array dimension should be 11 + 1 = 12.

    // char four[11] = "fundamental";
}
