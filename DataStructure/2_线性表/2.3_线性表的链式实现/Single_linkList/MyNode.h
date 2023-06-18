//
// Created by s1477 on 2023/6/17.
//

#ifndef INC_2_3_线性表的链式实现_MYNODE_H
#define INC_2_3_线性表的链式实现_MYNODE_H

#include <stdbool.h>

#define ElemType int
/**
 * define the node struct
 *
 * data is the Data Domain
 * next is the pointer which points the next node
 */
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

/**
 * define the operations on nodes
 */

/**
 * define the init operation on single linked list without head node
 * @param L
 * @return bool
 */
bool InitList(LinkList *L);

/**
 * define the init operation on single linked list with head node
 * @param L
 * @return bool
 */
bool InitList_Head(LinkList *L);

/**
 * define the get empty operation on single linked list
 * @param L
 * @return bool
 */
bool empty(LinkList L);

/**
 * insert element and this linked list hasn't head node
 * @param LinkList *L
 * @param index
 * @param e
 * @return bool
 */
bool ListInsert(LinkList *L, int index, ElemType e);


/**
 * insert element and this linked list has head node
 * @param LinkList *L
 * @param index
 * @param e
 * @return bool
 */
bool ListInsert_head(LinkList *L, int index, ElemType e);

/**
 * destory single linked list
 * @param LinkList *L
 * @return bool
 */

bool DestoryNode (LNode *p);

bool DestructionList(LinkList *L);


LNode * LocateElem (LinkList L, ElemType e);

int Length_head (LinkList L);

#endif //INC_2_3_线性表的链式实现_MYNODE_H
