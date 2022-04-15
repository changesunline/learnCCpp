//
// Created by zhout on 2021/5/13.
//

#include <stdio.h>
#include <stdlib.h>

int a;
void f(int *x) {
    ++*x;
}

void main() {
    a = 0;
    f(&a);
    printf("a: %d", a);
}