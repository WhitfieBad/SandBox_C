#include <stdio.h>
#include "List.h"

int main() {
    Node* list = CreateNode(1);
    AddTermBegin(&list, 2);
    AddTermBegin(&list, 3);
    AddTermBegin(&list, 6);
    AddTermBegin(&list, 5);
    AddTermTag(list, NULL, 0, 1);
    AddTermBegin(&list, 44);
    RemoveTermBegin(&list);
    RemoveTermEnd(&list);
    RemoveTermTag(&list, NULL, 3);
    DisplayList(list);
    FreeList(&list);
    return 0;
}
