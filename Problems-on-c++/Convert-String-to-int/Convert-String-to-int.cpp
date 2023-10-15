#include <iostream>
#include <string>
#include <cstring>

/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. 
This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached.
The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the 
integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so 
that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers 
greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
*/

int allNumbersCode[10];

bool isNumber(char c, int allNumbersCodeArray[]) {
    for (int i = 0; i < 10; i++) {
        if (static_cast<int>(c) == allNumbersCodeArray[i]) {
            return true;
        }
    }
    return false;
}

int myAtoi(std::string s) {
    const char* charArray = s.data();

    int minusSymbol = static_cast<int>('-');
    int result = 0;
    bool isMinus = false;

    for (int i = 0; i <= sizeof(charArray); i++) {
        if (isNumber(charArray[i], allNumbersCode)) {
            int numberValue = static_cast<int>(charArray[i]) - 48;
            result += numberValue;

            if (!isMinus && static_cast<int>(charArray[i - 1] == minusSymbol)) {
                isMinus = true;
            }

            if (isNumber(charArray[i + 1], allNumbersCode)) {
                result *= 10;
            }
        }
    }

    if (isMinus) {
        if (result < INT_MIN / 10) {
            return INT_MIN + 1;
        }

        return result * -1;
    }
    else {
        if (result > INT_MAX / 10) {
            return INT_MAX - 1;
        }

        return result;
    }
}

int main()
{
    for (int i = 0; i < 10; i++) {
        allNumbersCode[i] = static_cast<int>('0' + i);
    }

    std::string message = "";
    std::getline(std::cin, message);
    std::cout << myAtoi(message) << std::endl;
}
