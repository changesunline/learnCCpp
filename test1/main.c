//
// Created by hezy on 2021/3/2.
//
#include <stdio.h>
#include <stdarg.h>

//汉诺塔

//斐波那契数列 循环
unsigned int FibonacciByItarator(unsigned int n) {
    if (n == 1 || n == 0) {
       return n;
    }

    unsigned int prev = 0;
    unsigned int current = 1;

    for (int i = 0; i <= n-2; ++i) {
        unsigned int temp = current;
        current += prev;
        prev = temp;
    }
    return current;
}

//斐波那契数列 递归
unsigned int Fibonacci(unsigned int n) {
   if (n == 1 || n == 0) {
       return n;
   } else {
       return Fibonacci(n-1) + Fibonacci(n-2);
   }
}

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

//可变参数
void handleVarags(int arg_count,...) {
    va_list args;

    va_start(args, arg_count);
    for (int i = 0; i < arg_count; ++i) {
        int arg = va_arg(args, int);
        printf("%d: %d\n", i, arg);
    }

    va_end(args);
}

void main(void) {
    printf("Fibonacci(10): %d\n", Fibonacci(10));
    printf("FibonacciByItarator(10): %d\n", FibonacciByItarator(10));
}