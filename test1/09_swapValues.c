//
// Created by zhout on 2021/3/26.
//
#include <stdio.h>
#include <io_utils.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main() {
    int a = 0;
    int b = 1;

    swap(&a, &b);

    PRINT_INT(a);
    PRINT_INT(b);
}
