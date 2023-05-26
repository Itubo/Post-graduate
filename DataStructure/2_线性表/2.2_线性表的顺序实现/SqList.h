//
// Created by s1477 on 2023/5/26.
//
#include "SqListType.h"

#ifndef INC_2_2_线性表的顺序实现_SQLIST_H
#define INC_2_2_线性表的顺序实现_SQLIST_H

/*
 * 定义线性表的初始结构及操作
 * */


/*
 * 定义枚举用来表示函数返回状态
 * */
enum Status {
    OK      =  0,
    ERROR   =  1
};

typedef struct {
    ElemType * data;
    int length;
    int MaxSize;
}SqList_S;               //静态表

typedef struct {
    ElemType * data;
    int length;
    int MaxSize;
}SqList_D;              //动态表

/*
 * declare operation in sqlist
 * */
enum Status InitList(SqList_D  * L);
int Length(SqList_D * L);
int LocateElem(SqList_D * L, ElemType e);
enum Status GetElem(SqList_D * L, int i, ElemType * e);
enum Status ListInsert(SqList_D * L, int i, ElemType e);
enum Status ListDelete(SqList_D * L, int i, ElemType * e);
enum Status PrintList(SqList_D * L);
enum Status Empty(SqList_D * L);
enum Status DestroyList(SqList_D * L);



#endif //INC_2_2_线性表的顺序实现_SQLIST_H
