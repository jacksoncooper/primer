#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main()
{
    int dividend = 42;
    
    std::list<int> possible_divisors = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::vector<int> divisors = { };

    std::copy_if(
        possible_divisors.begin(),
        possible_divisors.end(),
        std::back_inserter(divisors),
        [dividend] (int divisor) -> bool {
            std::modulus<int> divides;
            return not divides(dividend, divisor);
        }
    );

    std::cout << "divisors of " << dividend << " from given set:" << std::endl;
    for (int divisor : divisors) std::cout << divisor << " ";
    std::cout << std::endl;
}
