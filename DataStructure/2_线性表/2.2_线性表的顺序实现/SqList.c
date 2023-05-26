//
// Created by s1477 on 2023/5/26.
//
#include "SqList.h"
#include <stdlib.h>



enum Status InitList(SqList_D * L) {
    L->MaxSize = 50;
    L->data = (ElemType *) malloc (L->MaxSize * sizeof (ElemType));
    if (!L->data) return ERROR;
    L->length = 0;
    return OK;
}

int Length(SqList_D * L) {
    if (L) {
        return L->length;
    }
    return ERROR;
}

int LocateElem(SqList_D * L, ElemType e) {
    int i;
    if (L) {
        for (i = 0; i < L->MaxSize; i++) {
            if (L->data[i] == e) {
                return i + 1;               //返回的是序号，并非标号
            }
        }
        if (i == L->length) {
            return 0;                       //没有该元素，则返回 0
        }
    }
    return ERROR;
}


enum Status GetElem(SqList_D * L, int i, ElemType * e) {
    if (L) {
        if (i < 1 || i >= L->MaxSize) {
            return ERROR;
        }
        else {
            *e =  L->data[i-1];
            return OK;
        }
    }
    return ERROR;
}

enum Status ListInsert(SqList_D * L, int i, ElemType e) {
    if (L && L->length <= L->MaxSize) {
        if (i < 1 || i > L->MaxSize) {
            return ERROR;
        }
        else {
            int j;
            //从顺序表最后复制元素
            for (j = L->length; j >= i; --j) {
                L->data[j] = L->data[j - 1];
            }
            //插入新元素
            L->data[i-1] = e;
            //更新实际数据长度
            L->length++;
            return OK;
        }
    }
    return ERROR;
}

enum Status ListDelete(SqList_D * L, int i, ElemType * e) {
    if (L) {
        if (i < 1 || i > L->MaxSize) {
            //将删除元素腹给 e
            *e = L->data[i-1];
            //L的长度 - 1
            L->length--;

            // 将元素前移
            for (int j = i - 1; j < L->length - 1; j++) {
                L->data[j] = L->data[j + 1];
            }

            return OK;
        }
    }
    return ERROR;
}

enum Status PrintList(SqList_D * L) {
    if (L) {
        for (int i = 0; i < L->length; i++) {
            printf("%d ",L->data[i]);
        }
        printf("\n");
        return OK;
    }
    return ERROR;
}

enum Status Empty(SqList_D * L) {
    return L->length == 0 ? OK : ERROR;
}


enum Status DestroyList(SqList_D * L) {
    if (L) {
        free(L->data);
        L = NULL;
        return OK;
    }
    return ERROR;
}


