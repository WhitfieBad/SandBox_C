//
// Created by whitfie on 4/23/21.
//

#ifndef SANDBOX_C_LIST_H
#define SANDBOX_C_LIST_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>


typedef void (*PrintFunction) (const void* o1);
typedef bool (*EqualsFunction) (const void * o1,const void* o2);

typedef struct {
    void* pData;
    struct Node* next;
}Node;

int CreateNode(Node** pNewNode, void* pElement, size_t sizeElement);

int FreeList(Node** pBeginNode);

int AddTermBegin(Node** pBeginNode, void* pElement, size_t sizeElemet);

int AddTermEnd(Node* beginNode, void* pElement, size_t sizeElement);

int AddTermTag(Node* pBeginNode, EqualsFunction equalsFunction,void* pTag, void* pElement, size_t sizeElemet);

int RemoveTermBegin(Node** pNode);

int RemoveTermEnd(Node** pBeginNode);

int RemoveTermTag(Node** pBeginNode, EqualsFunction equalsFunction, void* tag);

int GetEndNode(Node* pBeginNode, Node** pPreNode, Node** pEndNode);

int DisplayList(Node *pBeginNode, PrintFunction printFunction);

#endif //SANDBOX_C_LIST_H
