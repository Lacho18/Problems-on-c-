#include <iostream>
#include <vector>

using namespace std;

bool chechVector(vector<char> array) {
    for (int i = 0; i < array.size(); i++) {
        for (int j = i + 1; j < array.size(); j++) {
            if (array[i] == array[j] && (array[i] != '.' && array[j] != '.')) {
                return false;
            }
        }
    }

    return true;
}

bool isSubgridValid(vector<vector<char>>& board, int startRow, int startCol) {
    vector<bool> used(9, false); // Initialize an array to keep track of used numbers 1-9

    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            char cell = board[i][j];
            if (cell != '.') {
                int num = cell - '0';
                if (used[num - 1]) {
                    return false; // Duplicate number found in the subgrid
                }
                used[num - 1] = true;
            }
        }
    }

    return true; // No duplicates found in the subgrid
}

bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        vector<char> subVector = board[i];
        if (!chechVector(subVector)) {
            return false;
        }
    }

    for (int i = 0; i < board.size(); i++) {
        vector<char> subVector;
        for (int j = 0; j < board.size(); j++) {
            subVector.push_back(board[j][i]);
        }
        if (!chechVector(subVector)) {
            return false;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!isSubgridValid(board, i, j)) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                    {'.', '.', '.', '.', '8', '.', '.', '.', '9'}, };

    std::cout << isValidSudoku(board) << std::endl;
}
