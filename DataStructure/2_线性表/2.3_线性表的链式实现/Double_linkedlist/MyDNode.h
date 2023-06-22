//
// Created by s1477 on 2023/6/18.
//

#ifndef INC_2_3_线性表的链式实现_MYDNODE_H
#define INC_2_3_线性表的链式实现_MYDNODE_H
#include <stdbool.h>

#define ElemType int

/**
 * define the struct of Double-linked list
 *
 * the prior pointer points the last node
 * the next pointer points the next node
 *
 */
typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

/**
 * define the initiate function for DLinkList
 * @param L
 * @return
 */
bool InitDLinkList (DLinkList *L);

/**
 * Insert an element after this node
 * @param p
 * @param s
 * @return status (type is bool)
 */
bool InsertNextNode (DNode *p, DNode *s);

/**
 * delete an element after this node
 * @param p
 * @param e
 * @return
 */
bool DeleteNextNode (DNode *p, ElemType *e);

bool DestoryNode (DNode *p);

void DestoryList (DLinkList *L);

void showList(DLinkList *L);

#endif //INC_2_3_线性表的链式实现_MYDNODE_H
