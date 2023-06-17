//
// Created by s1477 on 2023/6/17.
//

#include <stdio.h>
#include "Single_linkList/MyNode.c"



int main() {
    printf("hello world!\n");
    LinkList L;

    if (InitList_Head(&L)) {
        printf("malloction succeed!\n");
    }
    else {
        printf("malloction failed!\n");
    }
    if (L == NULL) {
        printf("L --> NULL\n");
    }
    else {
        printf("L --> NOT NULL\n");
    }

    int i = 5;
    int temp = 0;
    while(i--) {
        int temp;
        printf("please input the number temp:");
        scanf("%d",&temp);
        if (ListInsert_head(&L, 1, temp)) {
            printf("Insert succeed!\n");
        }
    }
    showLinkedList(L);

    DestructionList(&L);
    if (L == NULL) {
        printf("destory succeed!\n");
    }
    else {
        printf("destory failed!\n");
    }
    return 0;
}

