#include <stdio.h>
#include "List.h"

int main() {
    Node* list = NULL;
    CreateNode(1, &list);
    AddTermBegin(&list, 2);
    AddTermBegin(&list, 3);
    AddTermBegin(&list, 6);
    AddTermBegin(&list, 5);
    AddTermEnd(list, 10);
    AddTermTag(list, NULL, 666, 2);
    RemoveTermTag(&list, NULL, 666);
    RemoveTermBegin(&list);
    DisplayList(list);
    FreeList(&list);
    return 0;
}
