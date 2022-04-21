//
// Created by zhout on 2021/5/13.
//

#include <stdio.h>
#include <stdlib.h>

void reverse(int a[], int left, int right, int k) {
    int temp;
    // 定义left为数组a最左端位置，right为a最右端位置
    for (int i=left, j=right; i<left+k && i<j; ++i,--j) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
void moveToEnd(int a[], int n, int k) {
    reverse(a, 0, k-1, k);
    reverse(a, 0, n-1, k);
}

void main() {
    int arr[] = {1,2,3,6,7,8};
    reverse(arr, 0, 3, 4);
    reverse(arr, 4, 5, 2);
    reverse(arr, 0, 5, 6); //整个数组逆置
    for (int i = 0; i < 6; ++i) {
        printf("%d", arr[i]);
    }
}