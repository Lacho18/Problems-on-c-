#include <iostream>
#include <limits>

/*
    Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes 
    the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
*/

int reverse(int number) {
    int multiplyer = 10;
    int result = 0;
    int lastNumber = 0;

    while (number != 0)
    {
        lastNumber = number % 10;

        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && lastNumber > 7)) {
            return 0;
        }
        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && lastNumber < -8)) {
            return 0;
        }

        result = (multiplyer * result) + lastNumber;
        number /= 10;
    }

    return result;
}

int main()
{
    int n = 0;
    std::cin >> n;
    std::cout << reverse(n) << std::endl;
}

