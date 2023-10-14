#include <iostream>
#include <limits>

/*

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

