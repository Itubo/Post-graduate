#include <stdio.h>
#include "SqList.h"
#include "SqList.c"
#include "work.c"

int main() {
//    system("chcp 65001");
    SqList_D sq ;
    if (InitList(&sq) == OK) {
        printf("init successful!\n");
    }

    for (int i = 0; i < 10; i++) {
        ListInsert(&sq, i + 1, i) == OK ? printf("insert successful\n")
        : printf("insert failure\n");
    }
    printf("it have element:%d \n", Length(&sq));

    if (PrintList(&sq) == 0) {
        printf("print have finished\n");
    }
    else {
        printf("print failure\n");
    }

    int res_des = DestroyList(&sq);
    if (res_des == OK) {
        printf("Destory successful\n");
    }
    else {
        printf("Destory failure\n");
    }

    return 0;
}

