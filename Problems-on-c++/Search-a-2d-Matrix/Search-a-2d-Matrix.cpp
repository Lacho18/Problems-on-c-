#include <iostream>
#include <vector>

using namespace std;

/*
    You are given an m x n integer matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.
    Given an integer target, return true if target is in matrix or false otherwise.

    You must write a solution in O(log(m * n)) time complexity.
    
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int index = 0;
   
    while (true) {
        if (matrix[index][0] < target && matrix[index][matrix[index].size() - 1] < target) {
            index++;
        }
        else if (matrix[index][0] <= target && matrix[index][matrix[index].size() - 1] >= target) {
            break;
        }
    }

    for (int i = 0; i < matrix[index].size(); i++) {
        if (matrix[index][i] == target) {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> firstArray = {1, 3, 5, 7};
    vector<int> secondArray = {10, 11, 16, 20};
    vector<int> thirthArray = {23, 30, 34, 60};

    vector<vector<int>> matrix;

    matrix.push_back(firstArray);
    matrix.push_back(secondArray);
    matrix.push_back(thirthArray);

    cout << searchMatrix(matrix, 1) << endl;
}
