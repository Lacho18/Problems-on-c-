#include <iostream>
#include <vector>

/*
    Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could
    represent. Return the answer in any order.

    A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/

using namespace std;

std::vector<std::vector<char>> letters = {
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'}
};

vector<string> letterCombinations(string digits) {
    std::vector<std::string> combinations;

    if (digits.empty()) {
        return combinations;
    }
    else {
        for (char digit : digits) {
            int number = digit - '0';
            if (number >= 2 && number <= 9) {
                int arrayIndex = number - 2;
                vector<char> partLetters = letters[arrayIndex];

                if (combinations.empty()) {
                    for (char partL : partLetters) {
                        combinations.push_back(string(1, partL));
                    }
                }
                else {
                    std::vector<std::string> newCombinations;
                    for (string combo : combinations) {
                        for (char partL : partLetters) {
                            newCombinations.push_back(string(combo + partL));
                        }
                    }
                    combinations = newCombinations;
                }
            }
        }
    }

    return combinations;
}

int main()
{
    std::vector<std::string> masiv;
    masiv = letterCombinations("237");

    for (int i = 0; i < masiv.size(); i++) {
        cout << masiv[i] << endl;
    }
}
