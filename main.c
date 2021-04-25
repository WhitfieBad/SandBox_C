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
    int* p0 = (int*) malloc(sizeof(int));
    *p0 = 1;
    int* p1 = (int*) malloc(sizeof(int));
    *p1 = 2;
    int* p2 = (int*) malloc(sizeof(int));
    *p2 = 3;
    int* p3 = (int*) malloc(sizeof(int));
    *p3 = 4;
    int* p4 = (int*) malloc(sizeof(int));
    *p4 = 6;
;
    Node* list = NULL;
    CreateNode(&list, p0);
    AddTermBegin(&list, p1);
    AddTermBegin(&list, p2);
    AddTermBegin(&list, p3);
    AddTermBegin(&list, p4);
    int tag = 2;
    RemoveTermEnd(&list);
    DisplayList(list, PrintInt);
    FreeList(&list);
    return 0;
}
