//
// Created by whitfie on 4/23/21.
//

#include "List.h"

Node* CreateNode(TYPE element) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode) {
        newNode->data = element;
    }
    return newNode;
}

void FreeList(Node** pNode) {
    if (!pNode) {
       return;
    }

    while (*pNode) {
        Node* deleteNode = *pNode;
        *pNode = (Node *) (*pNode)->next;
        free(deleteNode);
    }
}

void DisplayList(Node *pNode) {
    if (!pNode) {
        return;
    }

    while (pNode) {
        printf("%d \n", pNode->data);
        pNode = (Node *) pNode->next;
    }
}

_Bool RemoveTermBegin(Node** pNode) {
    if (!pNode || !(*pNode)) {
        return 0;
    }

    Node *nodeNext = (Node *) (*pNode)->next;
    free(*pNode);
    *pNode = nodeNext;
    return 1;
}

_Bool RemoveTermTag(Node** pNode, EqualsFunction equalsFunction, TYPE tag) {
    if (!pNode) {
        return 0;
    }

    if (equalsFunction == NULL) {
        equalsFunction = DefaultEquals;
    }

    Node* preNode = NULL;
    Node* nextNode = *pNode;

    while (nextNode) {
        if (equalsFunction(nextNode->data, tag)) {
            if (preNode) {
                preNode->next = nextNode->next;
                free(nextNode);
                nextNode = preNode;
            } else {
                RemoveTermBegin(pNode);
                continue;
            }
        } else {
            preNode = (Node *) nextNode;
        }
        nextNode = (Node *) nextNode->next;
    }
    return 1;
}

_Bool RemoveTermEnd(Node** pNode) {
    if (!pNode) {
        return 0;
    }

    Node* preNode = NULL;
    free(GetEndNode(*pNode, &preNode));
    if (preNode) {
        preNode->next = NULL;
    } else{
        *pNode = NULL;
    }
    return 1;
}

_Bool AddTermBegin(Node** pNode, TYPE data) {
    if (!pNode) {
        return 0;
    }

    Node* newNode = CreateNode(data);
    newNode->next = (struct Node *) *pNode;
    *pNode = newNode;
    return 1;
}

Node* GetEndNode(Node* beginNode, Node** preNode) {
    if(!beginNode) {
        return NULL;
    }

    while (beginNode->next) {
        if (preNode) {
            *preNode = beginNode;
        }
        beginNode = (Node *) beginNode->next;
    }
    return beginNode;
}

_Bool AddTermEnd(Node* beginNode, TYPE element) {
    Node* preNode = GetEndNode(beginNode, NULL);
    Node* newEndNode = (Node *) CreateNode(element);

    if (newEndNode && preNode) {
        preNode->next = (struct Node *) newEndNode;
        return 1;
    }
    return 0;
}

_Bool AddTermTag(Node* beginNode, EqualsFunction equalsFunction, TYPE element, TYPE tag) {
    if (!beginNode) {
        return 0;
    }

    if (equalsFunction == NULL) {
        equalsFunction = DefaultEquals;
    }

    while (beginNode) {
        if (equalsFunction(beginNode->data, tag)) {
            Node* nextNode = (Node *) beginNode->next;
            Node* newNode = (Node *) CreateNode(element);
            newNode->next = (struct Node *) nextNode;
            beginNode->next = (struct Node *) newNode;
            beginNode = (Node *) beginNode->next;
        }
        beginNode = (Node *) beginNode->next;
    }
    return 1;
}
