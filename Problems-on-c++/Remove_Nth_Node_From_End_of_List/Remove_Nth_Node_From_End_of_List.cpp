#include <iostream>

/*
    Given the head of a linked list, remove the nth node from 
    the end of the list and return its head.
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

int unsign(List*& begining) {
    List* p = begining;
    begining = begining->next;
    int n = p->value;
    delete p;
    return n;
}

List* removeNthFromEnd(List* head, int n) {
    List* targetElement = head;
    int index = 0;
    while (targetElement->next) {
        targetElement = targetElement->next;
        index++;
    }

    if (index + 1 >= n) {
        index = (index - (n - 1));
        targetElement = head;
        List* p = head;

        for (int i = 0; i < index; i++) {
            p = targetElement;
            targetElement = targetElement->next;
        }

        p->next = targetElement->next;
        if (index == 0) {
            head = p->next;
        }
        delete targetElement;
    }
    else {
        std::cout << "Too big number! Not enought elements in the list!" << std::endl;
    }
   

    return head;
}

void printListElements(List* begining) {
    while (begining) {
        std::cout << begining->value << ", ";
        begining = begining->next;
    }
}

int main()
{
    List* myList = nullptr;
    sign(&myList, 5);
    sign(&myList, 4);
    sign(&myList, 3);
    sign(&myList, 2);
    sign(&myList, 1);
    printListElements(myList);
    myList = removeNthFromEnd(myList, 123);
    std::cout << std::endl;
    printListElements(myList);
}
