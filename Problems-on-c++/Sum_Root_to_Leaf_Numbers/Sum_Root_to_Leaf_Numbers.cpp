#include <iostream>
#include <vector>

/*
    You are given the root of a binary tree containing digits from 0 to 9 only.

    Each root-to-leaf path in the tree represents a number.

    For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
    Return the total sum of all root-to-leaf numbers. 
    Test cases are generated so that the answer will fit in a 32-bit integer.

    A leaf node is a node with no children.
*/


//structure that represents a tree data structure
struct Tree {
    int value;
    Tree* left;
    Tree* right;
};

//function that prints the elements in the tree
void prefics(Tree* t) {
    if (t) {
        std::cout << t->value << std::endl;
        prefics(t->left);
        prefics(t->right);
    }
}

//function that adds elements in a tree wirt root t
void Add(Tree*& t, int number) {

    if (t) {
        if (!t->left) {
            Add(t->left, number);
            return;
        }

        if (!t->right) {
            Add(t->right, number);
            return;
        }

        if (t->left && t->right) {
            if (t->left->left == nullptr || t->left->right == nullptr) {
                Add(t->left, number);
                return;
            }
            else {
                Add(t->right, number);
                return;
            }
        }
    }
    else {
        t = new Tree;
        t->value = number;
        t->left = nullptr;
        t->right = nullptr;
    }
}

//function that completes the task
int sumNumbers(Tree* t) {
    static int sum = 0;
    static int currentNumber = 0;
    static int identifier = 0;

    if (t) {
        currentNumber += t->value;

        if (t->left) {
            identifier = 0;
            currentNumber *= 10;
            sumNumbers(t->left);
            if (identifier == 0) {
                sum += currentNumber;
            }
            identifier = 1;
            currentNumber /= 10;
        }

        if (t->right) {
            identifier = 0;
            currentNumber *= 10;
            sumNumbers(t->right);
            if (identifier == 0) {
                sum += currentNumber;
            }
            identifier = 1;
            currentNumber /= 10;
        }
    }

    return sum;
}

int main()
{
    Tree* root = nullptr;
    int array[] = { 3, 7, 5, 1, 2, 8 };
    int size = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < size; i++) {
        Add(root, array[i]);
    }

    prefics(root);
    std::cout << sumNumbers(root) << std::endl;
}
