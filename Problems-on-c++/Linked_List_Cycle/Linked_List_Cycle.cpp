#include <iostream>
#include <vector>

/*
    Given head, the head of a linked list, determine
    if the linked list has a cycle in it.

    There is a cycle in a linked list if there is some 
    node in the list that can be reached again by 
    continuously following the next pointer. Internally, 
    pos is used to denote the index of the node that tail's 
    next pointer is connected to. Note that pos is not passed as a 
    parameter.

    Return true if there is a cycle in the linked list. 
    Otherwise, return false.

    TASK COMPLETED WITH FUNCTION hasCycle(List* head)
*/

/*
    Given the head of a linked list, return the node where the 
    cycle begins. If there is no cycle, return null.

    There is a cycle in a linked list if there is some 
    node in the list that can be reached again by continuously 
    following the next pointer. Internally, pos is used to denote 
    the index of the node that tail's next pointer is connected to 
    (0-indexed). It is -1 if there is no cycle. Note that pos is not 
    passed as a parameter.

    Do not modify the linked list.

    TASK COMPLETED WITH FUNCTION detectCycle(List* head)
*/

using namespace std;

struct List {
    int value;
    List* next;
};

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

//Chechs if there is a cycle in the list. If thre is returns true
bool hasCycle(List* head) {
    List* p = head;
    vector<List*> masOfPointers = {};
    
    while (p != nullptr) {
        masOfPointers.push_back(p);
        p = p->next;

        for (int i = 0; i < masOfPointers.size(); i++) {
            if (p == masOfPointers[i]) {
                return true;
            }
        }
    }

    return false;
}

//creates a cycle by connecting the last element with element with index == target
void createCycle(List* head, int target) {
    List* p = head;
    List* q = head;
    int counter = 0;

    while (p->next) {
        p = p->next;
        if (counter < target) {
            counter++;
            q = q->next;
        }
    }

    p->next = q->next;
}

//if there is a cycle returns a pointer to the position where it appeares. If there is't return the null pointer
List* detectCycle(List* head) {
    List* p = head;
    vector<List*> masOfPointers = {};

    while (p != nullptr) {
        masOfPointers.push_back(p);
        p = p->next;

        for (int i = 0; i < masOfPointers.size(); i++) {
            if (p == masOfPointers[i]) {
                return masOfPointers[i];
            }
        }
    }

    return nullptr;
}

int getIndex(List* head, List* target) {
    int index = 0;
    List* p = head;

    while (p != target) {
        p = p->next;
        index++;
    }

    return index - 1;
}

int main()
{
    int array[] = { 3,2,0,-4 };
    int size = sizeof(array) / sizeof(array[0]);
    int pos = 1;

    List* list = nullptr;

    for (int i = 0; i < size; i++) {
        push(list, array[i]);
    }
    createCycle(list, pos);

    std::cout << "tail connected to node index " << getIndex(list, detectCycle(list)) << std::endl;
}

