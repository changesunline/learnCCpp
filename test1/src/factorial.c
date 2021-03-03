//
// Created by zhout on 2021/3/3.
//
#include <stdio.h>
#include "../include/factorial.h"

//阶层A!的计算 循环
unsigned int FactorialByItarator(unsigned int n) {
    unsigned int result = 1;
    for (unsigned int i = n; i > 0; i--) {
        result *= i;
    }
    return result;
}

//阶层A!的计算 递归
unsigned int Factorial(unsigned int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * Factorial(n - 1);
    }
}

