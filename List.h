//
// Created by whitfie on 4/23/21.
//

#ifndef SANDBOX_C_LIST_H
#define SANDBOX_C_LIST_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef _Bool (*EqualsFunction) (void* o1, void* o2);
typedef void (*PrintFunction) (void* o1);

typedef struct {
    void* pData;
    struct Node* next;
}Node;

int CreateNode(Node**, void*, size_t);

int FreeList(Node**);

int DisplayList(Node*, PrintFunction);

int RemoveTermEnd(Node**);

int RemoveTermBegin(Node**);

int AddTermEnd(Node*, void*, size_t);

int GetEndNode(Node*, Node**, Node**);

int AddTermBegin(Node **, void*, size_t);

int RemoveTermTag(Node**, EqualsFunction, void*);

int AddTermTag(Node*, EqualsFunction, void*, void*, size_t);

#endif //SANDBOX_C_LIST_H
