//
// Created by s1477 on 2023/6/17.
//

#include <stdlib.h>
#include <stdio.h>
#include "MyNode.h"


bool InitList(LinkList *L) {
    *L = NULL;
    return true;
}

bool InitList_Head(LinkList *L) {
    // malloc memory for the head node
    *L = (LNode *) malloc (sizeof(LNode));
    // memory allocation failed
    if (*L == NULL) {
        return false;
    }
    (*L)->next = NULL;
    return true;
}

bool empty(LinkList L) {
    return L->next==NULL;
}

bool ListInsert(LinkList *L, int i, ElemType e) {
    if (*L == NULL || i < 1) {
        return false;
    }
    if (i == 1) {
        LNode *s = (LNode *) malloc(sizeof (LNode));
        s->data = e;
        s->next = *L;
        *L = s;
        return true;
    }
    LNode *p;
    int j = 1;
    p = *L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }
    LNode * s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListInsert_head(LinkList *L, int i, ElemType e) {
    if (*L == NULL || i < 1) {
        return false;
    }
    LNode *p;
    int j = 0;
    p = *L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }
    LNode * s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//后插：
bool InsertNextNode (LNode *p, ElemType e) {
    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *) malloc (sizeof (LNode));
    if (s == NULL) {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertPriorNode (LNode *p, ElemType e) {
    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *) malloc (sizeof (LNode));
    s->data = p->data;
    s->next = p->next;
    p->data = e;
    p->next = s;
    return true;
}

bool DestructionList(LinkList *L) {
    if (*L == NULL) {
        printf("This single linked list haven't initated!\n");
        return false;
    }
    *L = NULL;
    return true;
}

LNode * LocateElem (LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

int Length_head (LinkList L) {
    int i = 0;
    LNode *p = L;
    while (p->next!=NULL) {
        p = p->next;
        i++;
    }
    return i;
}


bool showLinkedList(LinkList L) {
    if (L == NULL) {
        return false;
    }
    LNode *p = L->next;
    if (p == NULL) {
        printf("Warning!!! It seems that this linked list have no data\n");
        return true;
    }
    printf("\nshow begin:\n");
    printf("L------>head------>");
    while(p!=NULL) {
        printf("%d------->",p->data);
        p = p->next;
    }
    printf("NULL \n");
    printf("show finished\n");
    return true;
}
