#include <iostream>
#include <vector>
#include <string>

/*
    A valid IP address consists of exactly four integers separated by 
    single dots. Each integer is between 0 and 255 (inclusive) and 
    cannot have leading zeros.

    For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, 
    but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are 
    invalid IP addresses.
    Given a string s containing only digits, return all possible 
    valid IP addresses that can be formed by inserting dots into s. 
    You are not allowed to reorder or remove any digits in s. You may 
    return the valid IP addresses in any order.
*/

bool isValidPart(const std::string& part) {
    // Check if the part is a valid integer between 0 and 255
    if (part.empty() || (part.size() > 1 && part[0] == '0'))
        return false;

    int num = std::stoi(part);
    return num >= 0 && num <= 255;
}

void generateIPAddresses(std::vector<std::string>& result, const std::string& s, std::string current, int partCount, int startIndex) {
    if (partCount == 4) {
        // We've created a valid IP address with 4 parts
        if (startIndex == s.size()) {
            result.push_back(current);
        }
        return;
    }

    for (int i = startIndex; i < s.size(); ++i) {
        std::string part = s.substr(startIndex, i - startIndex + 1);

        if (isValidPart(part)) {
            // If the current part is a valid integer, add a dot and continue
            generateIPAddresses(result, s, current + part + (partCount < 3 ? "." : ""), partCount + 1, i + 1);
        }
        else {
            // Stop if the part is not valid
            break;
        }
    }
}

std::vector<std::string> restoreIPAddresses(const std::string& s) {
    std::vector<std::string> result;
    generateIPAddresses(result, s, "", 0, 0);
    return result;
}

int main() {
    std::string s = "25525511135";
    std::vector<std::string> validIPs = restoreIPAddresses(s);

    for (const std::string& ip : validIPs) {
        std::cout << ip << std::endl;
    }

    return 0;
}

