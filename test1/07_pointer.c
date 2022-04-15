//
// Created by zhout on 2021/3/9.
//
#include <stdio.h>
#include <io_utils.h>

void main(void) {
//    int a = 10;
//    scanf("%d", &a);

//    int *p = &a;
//    int **pp = &p;
//    PRINT_HEX(p);
//    PRINT_HEX(&a);
//    PRINT_INT(a);
//    PRINT_INT(*p);

//    PRINT_HEX(*pp);
//    PRINT_HEX(p);

//    int *const cp = &a;
//    int const *const cpp = &a;
//    int const *cppp = &a;

//    PRINT_INT(*cp);
//    PRINT_INT(*cp);
//    PRINT_INT(cppp);
//    PRINT_INT(a);
    int a = 5;
    int *p = &a;
    int **pp = &p;
//    *p = 2;
    PRINT_HEX(**pp);
    PRINT_HEX(a);
}
