//
// Created by whitfie on 4/23/21.
//
#include <memory.h>
#include "List.h"

static _Bool DefaultEquals(void* o1, void* o2) {
    return o1 == o2;
}

static void DefaulPrint(void* pObject){
    printf("%p \n", pObject);
}

int CreateNode(Node** pNewNode, void* pElement, size_t sizeElement) {
    *pNewNode = (Node*) malloc(sizeof(Node));
    void* pNewElement = malloc(sizeElement);

    if (*pNewNode && pNewElement) {
        memcpy(pNewElement, pElement, sizeElement);
        (*pNewNode)->pData = pNewElement;
        return 0;
    }
    return -1;
}

int FreeList(Node** pBeginNode) {
    if (!pBeginNode) {
       return -1;
    }

    while (*pBeginNode) {
        Node* pNodeDeleted = *pBeginNode;
        *pBeginNode = (Node *) (*pBeginNode)->next;
        free(pNodeDeleted->pData);
        free(pNodeDeleted);
    }
    return 0;
}

int DisplayList(Node *pBeginNode, PrintFunction printFunction) {
    if (!pBeginNode) {
        return -1;
    }

    if (!printFunction) {
        printFunction = DefaulPrint;
    }

    while (pBeginNode) {
        printFunction(pBeginNode->pData);
        pBeginNode = (Node *) pBeginNode->next;
    }
    return 0;
}

int RemoveTermBegin(Node** pNode) {
    if (!pNode || !(*pNode)) {
        return -1;
    }

    Node *nodeNext = (Node *) (*pNode)->next;
    free((*pNode)->pData);
    free(*pNode);
    *pNode = nodeNext;
    return 0;
}

int RemoveTermTag(Node** pBeginNode, EqualsFunction equalsFunction, void* tag) {
    if (!pBeginNode) {
        return -1;
    }

    if (!equalsFunction) {
        equalsFunction = DefaultEquals;
    }

    Node* preNode = NULL;
    Node* nextNode = *pBeginNode;

    int isCompleted = -1;

    while (nextNode) {
        if (equalsFunction(nextNode->pData, tag)) {
            if (preNode) {
                preNode->next = nextNode->next;
            } else {
                *pBeginNode = (Node *) nextNode->next;
            }
            Node* deleteNode = nextNode;
            nextNode = (Node *) nextNode->next;
            free(deleteNode->pData);
            free(deleteNode);
            isCompleted = 0;
        } else {
            preNode = nextNode;
            nextNode = (Node *) nextNode->next;
        }
    }
    return isCompleted;
}

int RemoveTermEnd(Node** pBeginNode) {
    Node* preNode = NULL;
    Node* endNode = NULL;

    if(GetEndNode(*pBeginNode, &preNode, &endNode) < 0){
        return -1;
    }

    free(endNode->pData);
    free(endNode);

    if (preNode) {
        preNode->next = NULL;
    } else{
        *pBeginNode = NULL;
    }
    return 0;
}

int AddTermBegin(Node** pBeginNode, void* pElement, size_t sizeElemet) {
    if (!pBeginNode) {
        return -1;
    }

    Node* newNode = NULL;
    if (CreateNode(&newNode, pElement, sizeElemet) < 0) {
        return -1;
    }

    newNode->next = (struct Node *) *pBeginNode;
    *pBeginNode = newNode;
    return 0;
}

int GetEndNode(Node* pBeginNode, Node** pPreNode, Node** pEndNode) {
    if(!pBeginNode) {
        return -1;
    }

    while (pBeginNode->next) {
        if (pPreNode) {
            *pPreNode = pBeginNode;
        }
        pBeginNode = (Node *) pBeginNode->next;
    }

    *pEndNode = pBeginNode;
    return 0;
}

int AddTermEnd(Node* beginNode, void* pElement, size_t sizeElement) {
    Node* preNode = NULL;
    Node* newEndNode = NULL;

    if(GetEndNode(beginNode, NULL, &preNode) < 0) {
        return -1;
    }

    if (CreateNode(&newEndNode, pElement, sizeElement) < 0) {
        return -1;
    }

    preNode->next = (struct Node *) newEndNode;
    return 0;
}

int AddTermTag(Node* pBeginNode, EqualsFunction equalsFunction,void* pTag, void* pElement, size_t sizeElemet) {
    if (!pBeginNode) {
        return -1;
    }

    if (!equalsFunction) {
        equalsFunction = DefaultEquals;
    }

    int isCompleted = -1;

    while (pBeginNode) {
        if (equalsFunction(pBeginNode->pData, pTag)) {
            Node* newNode = NULL;
            Node* nextNode = (Node *) pBeginNode->next;
            if (CreateNode(&newNode, pElement, sizeElemet) < 0) {
                return -1;
            }
            newNode->next = (struct Node *) nextNode;
            pBeginNode->next = (struct Node *) newNode;
            pBeginNode = (Node *) pBeginNode->next;
            isCompleted = 0;
        }
        pBeginNode = (Node *) pBeginNode->next;
    }
    return isCompleted;
}
