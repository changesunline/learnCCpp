//
// Created by zhout on 2021/3/9.
//
#include <stdio.h>
#include <io_utils.h>

void main(void) {
    int a = 10;
//    scanf("%d", &a);

    int *p = &a;
    int **pp = &*p;
    PRINT_HEX(p);
    PRINT_HEX(&a);
    PRINT_INT(a);
    PRINT_INT(*p);
}
