//
// Created by zhout on 2021/3/4.
//

#include <stdio.h>

//判断是否有c++语言
//#ifdef __cplusplus
//#endif

void dump(void) {
#ifdef DEBUG
    printf("debug\n");
#endif
    printf("hello world");
}

void main(void) {
    printf("__STDC_VERSION__: %ld\n", __STDC_VERSION__);
//    dump();
}