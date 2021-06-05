#include <string>
#include <iostream>

std::string global_str; // Default initialized by std::string.
int global_int;         // Default initialized to 0.

int main()
{
    int local_int;            // Uninitialized.
    std::string local_string; // Default initialized by std::string.

    std::cout << "My uninitialized integer: " << local_int << std::endl;
}
