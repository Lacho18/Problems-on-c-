#include <iostream>
#include <vector>

using namespace std;

/*
    Given an integer array nums where every element appears 
    three times except for one, which appears exactly once. 
    Find the single element and return it.

    You must implement a solution with a linear runtime 
    complexity and use only constant extra space.
*/

int singleNumber(vector<int> &nums) {
    vector<int> repeate = {};
    bool repeated = false;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i != j) {
                if (nums[i] == nums[j]) {
                    repeated = true;
                }
             }
        }
        if (!repeated) {
            return nums[i];
        }
        repeated = false;
    }
}

int main()
{
    vector<int> array = { 0,1,0,1,0,1,99 };
    std::cout << singleNumber(array) << std::endl;
}
