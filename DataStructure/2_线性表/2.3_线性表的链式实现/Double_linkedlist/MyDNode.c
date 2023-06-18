//
// Created by s1477 on 2023/6/18.
//

#include "MyDNode.h"
#include <stdio.h>
#include <stdlib.h>

bool InitDLinkList (DLinkList *L) {
    *L = (DNode *) malloc (sizeof (DNode));
    if (L == NULL) {
        printf("memory is not enough!\n");
        return false;
    }
    (*L)->next = NULL;
    (*L)->prior = NULL;
    return true;
}

bool DeleteNextNode (DNode *p, ElemType *e) {
    if (p == NULL) return false;
    DNode *q = p->next;
    // the node after p is NULL (p node is the last one)
    if (q == NULL) return false;
    p->next = q->next;
    if (q->next != NULL) {
        q->next->prior = p;
    }
    *e = q->data;
    free(q);
    q = NULL;
    return true;
}

bool DestoryNode (DNode *p) {
    //p is NULL
    if (p == NULL) return false;
    DNode *q = p->next;
    // the node after p is NULL (p node is the last one)
    if (q == NULL) return false;
    p->next = q->next;
    if (q->next != NULL) {
        q->next->prior = p;
    }
    free(q);
    q = NULL;
    return true;
}

void DestoryList(DLinkList *L) {
    if (*L == NULL) {
        printf("this linked list is NULL!\n");
    }
    //use while free node
    while ((*L)->next != NULL) {
        DestoryNode(*L);
    }
    *L = NULL;
}
