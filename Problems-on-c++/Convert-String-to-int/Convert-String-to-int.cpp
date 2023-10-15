#include <iostream>
#include <string>
#include <cstring>

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
