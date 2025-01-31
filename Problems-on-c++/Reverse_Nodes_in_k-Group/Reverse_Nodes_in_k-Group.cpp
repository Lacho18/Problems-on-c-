#include <iostream>

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

void printListElements(List* begining) {
    while (begining) {
        std::cout << begining->value << ", ";
        begining = begining->next;
    }
}

List* reverseKGroup(List* head, int k) {
    List* p = head;
    int size = 0;

    while (p) {
        p = p->next;
        size++;
    }

    p = head;

    List* newList = nullptr;
    List* begining = newList;
    int interval = 1;
    while (interval * k <= size) {
        List* q = p;
        List* reverse = nullptr;
        for (int i = 0; i < k; i++) {
            sign(&reverse, q->value);
            q = q->next;
        }
        //q = q->next;
        
        List* lastElementSubList = reverse;
        while (lastElementSubList->next) {
            lastElementSubList = lastElementSubList->next;
        }
        p = reverse;
        lastElementSubList->next = q;
        //p = lastElementSubList;
        newList = p;
        interval++;
    }

    head = newList;
    return head;
}

int main()
{
    List* myList = nullptr;
    push(myList, 1);
    push(myList, 2);
    push(myList, 3);
    push(myList, 4);
    push(myList, 5);
    push(myList, 6);
    myList = reverseKGroup(myList, 3);
    printListElements(myList);
}

