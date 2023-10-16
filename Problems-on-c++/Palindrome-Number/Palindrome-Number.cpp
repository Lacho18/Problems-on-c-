#include <iostream>

/*
    Given an integer x, return true if x is a palindrome, and false otherwise. (Value 121, when it is read from left to right and is the same
    like when it read from right to left)
*/

bool isPalindrome(int x) {
    int reverseOnX = 0;
    int newX = x;

    while (newX != 0) {
        reverseOnX += newX % 10;
        newX /= 10;
        if (newX != 0) {
            reverseOnX *= 10;
        }
    }

    if (reverseOnX == x && x > 0) {
        return true;
    }
    return false;
}

int main()
{
    int n = 0;
    std::cin >> n;
    std::cout << isPalindrome(n) << std::endl;
}
