#include <iostream>

/*
    Given a linked list, swap every two adjacent nodes and return its head. 
    You must solve the problem without modifying the values in the list's 
    nodes (i.e., only nodes themselves may be changed.)
*/

struct List {
    int value;
    List* next;
};

void sign(struct List** begining, int n) {
    if (!begining) {
        List* p = *begining;
        p = new List;
        p->value = n;
        p->next = nullptr;
    }
    else {
        List* p = new List;
        p->value = n;
        p->next = *begining;
        *begining = p;
    }
}

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

int deleteSpecificValue(List* begining, int key) {
    List* p = begining;
    List* q = begining;

    while (p->value != key) {
        q = p;
        p = p->next;
    }

    q->next = p->next;
    int n = p->value;
    delete p;
    return n;
}

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

List* swapPairs(List* head) {
    List* p = head;

    while (p->next) {
        if (p->next) {
            int n = deleteSpecificValue(head, p->next->value);
            if (p != head) {
                addBeforeKeyValue(head, n, p->value);
            }
            else {
                sign(&head, n);
            }
            if (p->next) {
                p = p->next;
            }
            else {
                break;
            }
        }
    }

    return head;
}

int main()
{
    List* list = nullptr;

    push(list, 1);
    push(list, 2);
    push(list, 3);
    push(list, 4);
    push(list, 5);
    push(list, 6);
    push(list, 7);
    printListElements(list);
    std::cout << std::endl;
    list = swapPairs(list);
    printListElements(list);
}
