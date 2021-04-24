//
// Created by whitfie on 4/23/21.
//

#include "List.h"

static _Bool DefaultEquals(TYPE o1, TYPE o2) {
    return o1 == o2;
}

int CreateNode(TYPE element, Node** pNode) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode) {
        newNode->data = element;
        *pNode = newNode;
        return 0;
    }
    return -1;
}

int FreeList(Node** pNode) {
    if (!pNode) {
       return -1;
    }

    while (*pNode) {
        Node* deleteNode = *pNode;
        *pNode = (Node *) (*pNode)->next;
        free(deleteNode);
    }
    return 0;
}

int DisplayList(Node *pNode) {
    if (!pNode) {
        return -1;
    }

    while (pNode) {
        printf("%d \n", pNode->data);
        pNode = (Node *) pNode->next;
    }
    return 0;
}

int RemoveTermBegin(Node** pNode) {
    if (!pNode || !(*pNode)) {
        return -1;
    }

    Node *nodeNext = (Node *) (*pNode)->next;
    free(*pNode);
    *pNode = nodeNext;
    return 0;
}

int RemoveTermTag(Node** pNode, EqualsFunction equalsFunction, TYPE tag) {
    if (!pNode) {
        return -1;
    }

    if (!equalsFunction) {
        equalsFunction = DefaultEquals;
    }

    Node* preNode = NULL;
    Node* nextNode = *pNode;

    int isCompleted = -1;

    while (nextNode) {
        if (equalsFunction(nextNode->data, tag)) {
            isCompleted = 0;
            if (preNode) {
                preNode->next = nextNode->next;
                free(nextNode);
                nextNode = preNode;
            } else {
                if (RemoveTermBegin(pNode) < 0) {
                   return -1;
                }
                continue;
            }
        } else {
            preNode = (Node *) nextNode;
        }
        nextNode = (Node *) nextNode->next;
    }
    return isCompleted;
}

int RemoveTermEnd(Node** pNode) {
    Node* preNode = NULL;
    Node* endNode = NULL;

    if(GetEndNode(*pNode, &preNode, &endNode) < 0){
        return -1;
    }

    free(endNode);

    if (preNode) {
        preNode->next = NULL;
    } else{
        *pNode = NULL;
    }
    return 1;
}

int AddTermBegin(Node** pNode, TYPE data) {
    if (!pNode) {
        return -1;
    }

    Node* newNode = NULL;
    if (CreateNode(data, &newNode) < 0) {
        return -1;
    }

    newNode->next = (struct Node *) *pNode;
    *pNode = newNode;
    return 0;
}

int GetEndNode(Node* beginNode, Node** preNode, Node** endNode) {
    if(!beginNode) {
        return -1;
    }

    while (beginNode->next) {
        if (preNode) {
            *preNode = beginNode;
        }
        beginNode = (Node *) beginNode->next;
    }

    *endNode = beginNode;
    return 0;
}

int AddTermEnd(Node* beginNode, TYPE element) {
    Node* preNode = NULL;
    Node* newEndNode = NULL;

    if(GetEndNode(beginNode, NULL, &preNode) < 0) {
        return -1;
    }

    if (CreateNode(element, &newEndNode) < 0) {
        return -1;
    }

    preNode->next = (struct Node *) newEndNode;
    return 0;
}

int AddTermTag(Node* beginNode, EqualsFunction equalsFunction, TYPE element, TYPE tag) {
    if (!beginNode) {
        return -1;
    }

    if (!equalsFunction) {
        equalsFunction = DefaultEquals;
    }

    int isCompleted = -1;

    while (beginNode) {
        if (equalsFunction(beginNode->data, tag)) {
            Node* newNode = NULL;
            Node* nextNode = (Node *) beginNode->next;
            if (CreateNode(element, &newNode) < 0) {
                return -1;
            }
            newNode->next = (struct Node *) nextNode;
            beginNode->next = (struct Node *) newNode;
            beginNode = (Node *) beginNode->next;
            isCompleted = 1;
        }
        beginNode = (Node *) beginNode->next;
    }
    return isCompleted;
}
