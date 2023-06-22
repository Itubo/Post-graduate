//
// Created by s1477 on 2023/6/17.
//

#include <stdio.h>
#include <stdlib.h>
//#include "Single_linkList/MyNode.c"
//#include "Double_linkedlist/MyDNode.c"
#include "Static_linkedlist/MySNode.c"

int main() {
    printf("hello world!\n");
    DLinkList L;

    if (InitDLinkList(&L)) {
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
    while(i--) {
        int temp;
        printf("please input the number temp:");
        scanf("%d",&temp);
        DNode * p = (DNode *) malloc (sizeof(DNode));
        p->data = temp;
        if (InsertNextNode(L, p)) {
            printf("Insert succeed!\n");
        }
    }
    showList(&L);

    DestoryList(&L);
    if (L == NULL) {
        printf("destory succeed!\n");
    }
    else {
        printf("destory failed!\n");
    }
    return 0;
}

