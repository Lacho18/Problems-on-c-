#include <iostream>

/*
    Given the head of a singly linked list where elements are 
    sorted in ascending order, convert it to a height-balanced
    binary search tree.         
*/

struct Tree {
    int value;
    Tree* left;
    Tree* right;
};

void prefics(Tree* root) {
    if (root) {
        std::cout << root->value << " ";
        prefics(root->left);
        prefics(root->right);
    }
}

void add(Tree*& root, int number) {
    if (root) {
        if (root->value > number) {
            add(root->left, number);
        }
        else {
            add(root->right, number);
        }
    }
    else {
        root = new Tree;
        root->value = number;
        root->left = nullptr;
        root->right = nullptr;
    }
}

int main()
{
    Tree* root = nullptr;
    int array[] = { -10,-3,0,5,9};
    int size = sizeof(array) / sizeof(array[0]);
    int middle = size / 2;
    int middleElement = array[middle];
    int swap = array[0];
    array[0] = array[middle];
    array[middle] = -100000;
    int index = 1;

    int c = array[index];
    array[index] = swap;

    index++;
    if (array[index] != -100000) {
        while (array[index] != -100000) {
            int forSwap = array[index];
            array[index] = c;
            c = forSwap;
            index++;
        }
    }
    else {
        array[index] = c;
    }
    
    
    for (int i = 1; i < size; i+=2) {
        if (i < size) {
            int c = array[i];
            array[i] = array[i + 1];
            array[i + 1] = c;
        }
    }

    for (int i = 0; i < size; i++) {
        add(root, array[i]);
    }

    prefics(root);
}

