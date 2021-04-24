//
// Created by whitfie on 4/23/21.
//

#ifndef SANDBOX_C_LIST_H
#define SANDBOX_C_LIST_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef int TYPE;
typedef _Bool (*EqualsFunction) (TYPE o1, TYPE o2);

typedef struct {
    TYPE data;
    struct Node* next;
}Node;

Node* CreateNode();

void FreeList(Node**);

void DisplayList(Node*);

_Bool RemoveTermBegin(Node**);

_Bool RemoveTermEnd(Node**);

_Bool RemoveTermTag(Node**, EqualsFunction, TYPE);

bool AddTermBegin(Node **, TYPE);

Node* GetEndNode(Node*, Node**);

_Bool AddTermEnd(Node*, TYPE);

_Bool AddTermTag(Node*, EqualsFunction, TYPE, TYPE);

static _Bool DefaultEquals(TYPE o1, TYPE o2) {
    return o1 == o2;
}

#endif //SANDBOX_C_LIST_H
