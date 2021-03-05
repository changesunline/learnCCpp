//
// Created by zhout on 2021/3/4.
//
#include <stdio.h>
#include <stdarg.h>

// 宏调用宏
#define PRINTFLN(value, ...) printf(value"\n", ##__VA_ARGS__)
#define PRINTFFILELINE_KV(value) PRINTFLN(#value": %d", value)

//宏函数 - 打印当前文件路径：运行的行 运行的函数
#define PRINTFFILELINE(format, ...) printf("("__FILE__": %d) %s: "format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__)

//宏函数
#define PRINTLNF(format, ...) printf(format"\n", ##__VA_ARGS__)

//普通函数
void printLnf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    printf("\n");
    va_end(args);
}

void main(void) {
//    printLnf("hello %s", "zhouting");
//    printLnf("hello %s", "fasdfa");
//    printLnf("hello %s", "gjgjsf");

//    PRINTLNF("HELLO %s, %s", "zhangsan", "lisi");
//    PRINTLNF("HELLO");
//    PRINTLNF("HELLO %s, %s", "wangwu", "zhouliu");

//    PRINTFFILELINE("你好 %s", "zhangsan");

    int abc = 3;
    PRINTFFILELINE_KV(++abc);
}