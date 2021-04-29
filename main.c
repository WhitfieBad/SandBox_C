#include <stdio.h>
#include "List.h"

void printInt(const void* const value) {

    const int valueInt = *(int*) value;
    printf("%d \n", valueInt);
}

Node* addTwoNumbers(Node* l1, Node* l2){
    Node* SumList = NULL;

    while (l1 && l2) {
        int* a = (int*) l1->pData;
        int* b = (int*) l2->pData;

        int sum = *a + *b;

        AddTermBegin(&SumList, &sum, sizeof (int));

        l1 = (Node *) l1->next;
        l2 = (Node *) l2->next;
    }
    return SumList;
}

int main() {
    Node* listA = NULL;
    int value = 2;
    CreateNode(&listA, &value, sizeof(value));
    value = 4;
    AddTermBegin(&listA, &value, sizeof(value));
    value = 3;
    AddTermBegin(&listA, &value, sizeof(value));

    Node* listB = NULL;
    value = 5;
    AddTermBegin(&listB, &value, sizeof(value));
    value = 6;
    AddTermBegin(&listB, &value, sizeof(value));
    value = 4;
    AddTermBegin(&listB, &value, sizeof(value));

    Node* sumNode = addTwoNumbers(listA, listB);
    DisplayList(sumNode, printInt);

    FreeList(&listB);
    FreeList(&listA);
    FreeList(&sumNode);
    return 0;
}
