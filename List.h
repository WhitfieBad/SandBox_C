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

int CreateNode();

int FreeList(Node**);

int DisplayList(Node*);

int RemoveTermEnd(Node**);

int AddTermEnd(Node*, TYPE);

int RemoveTermBegin(Node**);

int AddTermEnd(Node*, TYPE);

int GetEndNode(Node*, Node**, Node**);

int AddTermBegin(Node **, TYPE);

int RemoveTermTag(Node**, EqualsFunction, TYPE);

int AddTermTag(Node*, EqualsFunction, TYPE, TYPE);

#endif //SANDBOX_C_LIST_H
