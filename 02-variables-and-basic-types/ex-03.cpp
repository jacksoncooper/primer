#include <iostream>

int main()
{
    unsigned u = 10, u2 = 42;

    std::cout << "1. " << u2 - u << std::endl;

    // The subtraction of two unsigned integers yields an unsigned integer.

    // Computes 42 - 10, the result is 32.

    std::cout << "2. " << u - u2 << std::endl;

    // Computes 10 - 42, the result is -32 % 4294967296 [1].

    // -32 % 4294967296 = -1 * 4294967296 + 4294967264

    // So the expression evaluates to 4294967264.

    // [1] sizeof(unsigned) returns 4 bytes on this machine, which is 32 bits.
    // So an unsigned integer can represent 2^32 or 4294967296 values.

    int i = 10, i2 = 42;

    std::cout << "3. " << i2 - i << std::endl;

    // Evaluates to 42 - 10 or 32.

    std::cout << "4." << i - i2 << std::endl;

    // Evaluates to 10 - 42 or -32.

    std::cout << "5. " << i - u << std::endl;

    // The integer value is converted to an unsigned integer.

    // Computes 10 - 10, the result is 0.

    std::cout << "6. " << u - i << std::endl;

    // Computes 10 - 10, the result is 0.
}
