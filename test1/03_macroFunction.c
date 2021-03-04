//
// Created by zhout on 2021/3/4.
//
#include <stdio.h>
#define MAX(a, b) (a) > (b) ? (a) : (b)

//'\'换行符
#define IS_HEX_CHARACTER(ch) \
(xxxx) || \

int Max(a, b) {
    return a > b ? a : b;
}

void main(void) {
    int max = MAX(1, 3);
    int max2 = MAX(1, MAX(3, 4));

    int max4 = MAX(max++, 5);

    int max3 = Max(1,Max(3,4));

    printf("max: %d\n", max);
    printf("max2: %d\n", max2);
    printf("max3: %d\n", max3);
    printf("max4: %d\n", max4);
};