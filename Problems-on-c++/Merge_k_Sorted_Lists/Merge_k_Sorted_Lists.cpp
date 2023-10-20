#include <iostream>
#include <vector>

//Task
/*
    You are given an array of k linked-lists lists, each linked-list is 
    sorted in ascending order.

    Merge all the linked-lists into one sorted linked-list and return it.
*/

struct List {
    int value;
    List* next;
};

//Add number n BEFORE the value of key in the list(key is a value that already exists in the list)
void addBeforeKeyValue(List*& begining, int n, int key) {
    List* p = begining;
    List* q = begining;

    while (p->value != key) {
        q = p;
        p = p->next;
    }

    List* newValue = new List;
    newValue->value = n;
    q->next = newValue;
    newValue->next = p;
}

//Add number n AFTER the value of key in the list(key is a value that already exists in the list)
void addAfterKeyValue(List*& begining, int n, int key) {
    List* p = begining;

    while (p->value != key) {
        p = p->next;
    }

    List* newElement = new List;
    newElement->value = n;
    newElement->next = p->next;
    p->next = newElement;
}

//Add element n at the end of the list
void push(List*& begining, int n) {
    if (!begining) {
        begining = new List;
        begining->value = n;
        begining->next = nullptr;
    }
    else {
        List* p = begining;
        while (p->next) {
            p = p->next;
        }
        List* q = new List;
        q->value = n;
        q->next = nullptr;
        p->next = q;
    }
}

//delete a element from the end of the list
int pop(List* begining) {
    List* p = begining;
    List* q = p;
    while (p->next)
    {
        q = p;
        p = p->next;
    }
    int n = p->value;
    delete p;
    q->next = nullptr;
    return n;
}

//prints all elements in the list, which is given as paramether (begining)
void printListElements(List* begining) {
    while (begining) {
        std::cout << begining->value << ", ";
        begining = begining->next;
    }
}

//a function that completes the task. It takes a masiv(vector) of lists and sort them in one list and returns it's head
List* mergeKLists(std::vector<List*>& lists) {
    List* newList = nullptr;

    for (int i = 0; i < lists.size(); i++) {
        List* currentList = lists[i];
        if (!newList) {
            while (currentList) {
                push(newList, currentList->value);
                currentList = currentList->next;
            }
        }
        else {
            List* p = newList;
            while (currentList) {
                if (p->value > currentList->value) {
                    addBeforeKeyValue(newList, currentList->value, p->value);
                }
                else if (p->value == currentList->value) {
                    addAfterKeyValue(newList, currentList->value, p->value);
                }
                else {
                    if (p->next) {
                        p = p->next;
                        continue;
                    }
                    else {
                        push(newList, currentList->value);
                    }
                }
                currentList = currentList->next;
            }
        }
    }

    return newList;
}

int main()
{
    List* first = nullptr;
    List* second = nullptr;
    List* thirth = nullptr;

    push(first, 1);
    push(first, 4);
    push(first, 5);
    push(second, 1);
    push(second, 3);
    push(second, 3);
    push(second, 4);
    push(second, 7);
    push(thirth, 2);
    push(thirth, 6);
    push(thirth, 18);

    std::vector<List*> lists;
    lists.push_back(first);
    lists.push_back(second);
    lists.push_back(thirth);

    List* sortedElementsList = nullptr;
    sortedElementsList = mergeKLists(lists);
    printListElements(sortedElementsList);
}

