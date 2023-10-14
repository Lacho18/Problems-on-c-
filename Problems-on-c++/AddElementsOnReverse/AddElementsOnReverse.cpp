#include <iostream>

/*
    There are two non-empty linked lists representing two non-negative integers. The digits are stored in 
    reverse order, and each of their nodes contains a single digit. Add the two numbers and return 
    the sum as a linked list.
*/

void printMessage(const char* message) {
    std::cout << message << std::endl;
}

void printMessage(int message) {
    std::cout << message << std::endl;
}

struct List {
    int value;
    List* next;
};

void sign(struct List** begining,int n) {
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

int unsign(List* &begining) {
    List* p = begining;
    begining = begining->next;
    int n = p->value;
    delete p;
    return n;
}

void push(List* &begining, int n) {
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

int main()
{
    List* firstList = nullptr;
    List* secondList = nullptr;

    //firstList - [9, 9, 9, 9, 9, 9, 9]
    push(firstList, 9);
    push(firstList, 9);
    push(firstList, 9);
    push(firstList, 9);
    push(firstList, 9);
    push(firstList, 9);
    push(firstList, 9);

    //secondList - [9, 9, 9, 9]
    push(secondList, 9);
    push(secondList, 9);
    push(secondList, 9);
    push(secondList, 9);

    int number1 = 0;
    int multiplyer = 1;
    List* start = firstList;

    while (start)
    {
        number1 = (multiplyer * start->value) + number1;
        multiplyer *= 10;
        start = start->next;
    }

    int number2 = 0;
    multiplyer = 1;
    start = secondList;

    while (start)
    {
        number2 = (multiplyer * start->value) + number2;
        multiplyer *= 10;
        start = start->next;
    }

    int sum = number1 + number2;
    List* resultList = nullptr;
    while (sum != 0) {
        int lastNumber = sum % 10;
        push(resultList, lastNumber);
        sum /= 10;
    }
    
    //result - [8, 9, 9, 9, 0, 0, 0, 1]
    printListElements(resultList);
}

