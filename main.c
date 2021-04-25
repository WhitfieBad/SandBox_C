#include <stdio.h>
#include "List.h"

static void PrintInt(void* pObject){
    int* d = (int *) pObject;
    printf("%d \n", *d);
}

static _Bool EqualsFunctionInt(void* o1, void* o2) {

    int* a = (int *) o1;
    int* b = (int *) o2;
    return *a == *b;
}

int main() {

    int value1 = 1;
    int value2 = 2;
    int value3 = 3;
    int value4 = 4;

    Node* list = NULL;
    CreateNode(&list, &value1, sizeof(int));
    AddTermBegin(&list, &value2, sizeof(int));
    AddTermBegin(&list, &value3, sizeof(int));
    AddTermBegin(&list, &value4, sizeof(int));
    AddTermBegin(&list, &value4, sizeof(int));

    AddTermTag(list, EqualsFunctionInt, &value3, &value4, sizeof(int));
    DisplayList(list, PrintInt);
    FreeList(&list);
    return 0;
}
