//
// Created by s1477 on 2023/5/26.
//

/*  王道课后题
 *  2.2
 * */

#include <stdio.h>
#include <stdbool.h>
#include "SqList.h"
#include "SqList.c"

//删除顺序表中具有最小值的元素。
ElemType work_01(SqList_D * L);
void work_02(SqList_D * L);

int main() {

    SqList_D sqListD;
    SqList_D * sq = &sqListD ;
    if (InitList(sq) == OK) {
        printf("init successful!\n");
    }

//    for (int i = 0; i < 10; i++) {
//        ListInsert(sq, i + 1,  i) == OK ? printf("insert successful\n")
//                                        : printf("insert failure\n");
//    }
    ListInsert(sq, 1, 5);
    ListInsert(sq, 1, 6);
    ListInsert(sq, 1, 3);
    ListInsert(sq, 1, 8);
    ListInsert(sq, 1, 1);
    ListInsert(sq, 1, 9);
    ListInsert(sq, 1, 7);
    ListInsert(sq, 1, 2);
    ListInsert(sq, 1, 10);
//    ListInsert(sq,1,1);


    printf("it have element:%d \n", Length(sq));

    if (PrintList(sq) == 0) {
        printf("print have finished\n");
    }
    else {
        printf("print failure\n");
    }


    ElemType res = work_01(sq);

    printf("the number is : %d\n", res);
    PrintList(sq);

    return 0;
}

ElemType work_01(SqList_D * L) {
//    printf("L = %d",L);
    if (L != NULL) {
        int min_num = L->data[0];
        int i = 1;
        int index = 0;
        for (i; i < L->length; i++) {
            //循环比较，找出最小值。
            if (L->data[i] < min_num) {
                min_num = L->data[i];
                index = i;
            }
        }
        //将最后一个元素放入空出的位置
        //考虑最小的元素在最后一个
        if (index == L->length - 1) {
            if (index == 0) {
                printf("the des is not clarity");
                return ERROR;
            }
            else {
                L->data[index] = L->data[index - 1];
            }
        }
        else {
            L->data[index] = L->data[L->length - 1];
        }
        return min_num;
    }
    printf("ERROR!\n");
    return ERROR;
}

void work_02(SqList_D * L) {
    if (L) {
        ElemType temp;
        for (int i = 0; i < L->length / 2; i++) {
            temp =  L->data[i];
            L->data[i] = L->data[L->length - i - 1];
            L->data[L->length - i - i] = temp;
        }
    }
}

void work_03(SqList_D * L, ElemType x) {
    //其中， k 用来标记数组元素的个数。
    int k = 0,i;
    for (i = 0; i < L->length; i++) {
        //挑选不等于 x 的元素
        if(L->data[i] != x) {
            //只要数组元素不等于 x 就将其移至最后一个不等于 x 的元素的后面，下标为 k
            L->data[k] = L->data[i];
            k++;
        }
    }
    //修改数组元素个数为 k 个
    L->length = k;
}

/*
 * 删除给定 s t 之间的所有元素。
 * */

bool work_04(SqList_D * L, int s, int t) {
    if (L) {
        if (s < t || L->length == 0) {
            printf("参数不合法，删除失败！");
            return false;
        }
        int i,j;
        //找到 s 的位置
        for (i = 0; i < L->length && L->data[i] < s; i++);
        //全部都小于 s 的情况。
        if (i >= L->length) {
            return false;
        }
        //找到 j
        for (j = i; j < L->length && L->data[j] < t; j++);

    }
}






