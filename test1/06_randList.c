//
// Created by zhout on 2021/3/8.
//
#include <stdio.h>
#include <io_utils.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER_COUNT 10

//交换元素位置
void SwapElements(int array[], int first, int second) {
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}

void ShuffleArray(int array[], int length) {
    srand(time(NULL));
    for (int i = length - 1; i > 0; --i) {
        int random_num = rand() % i;
        SwapElements(array, i, random_num);
    }
}

//找出二分点
int Partition(int array[], int low, int high) {
    int pivot = array[high];
    int partition = low;
    for (int i = low; i < high; ++i) {
        if (array[i] < pivot) {
            SwapElements(array, i, partition);
            partition++;
        }
    }
    SwapElements(array, partition, high);
    return partition;
}
//快速排序
void QuickSort(int array[], int low, int high) {
    if (low >= high) return;
    int partition = Partition(array, low, high);
    QuickSort(array, low, partition-1);
    QuickSort(array, partition+1, high);
}

void main(void) {
    int array[PLAYER_COUNT];
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        array[i] = i;
    }

    ShuffleArray(array, PLAYER_COUNT);
    PRINT_INT_ARRAY(array, PLAYER_COUNT);

    QuickSort(array, 0, PLAYER_COUNT);
    PRINT_INT_ARRAY(array, PLAYER_COUNT);
}