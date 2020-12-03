
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

/*
 *函数名：display
 *作用：打印数组元素
 *参数：array - 打印的数组，maxlen - 数组元素个数
 *返回值：无
 */
void display(int array[], int maxlen) {
    int i;

    for (i = 0; i < maxlen; i++) {
        printf("%-3d", array[i]);
    }
    printf("\n");
}

/*
 *函数名：QuickSort
 *作用：快速排序算法
 *参数：
 *返回值：无
 */
void QuickSort(int *arr, int low, int high) {
    if (low < high) {
        int i = low;
        int j = high;
        int k = arr[low];
        while (i < j) {
            // 从右向左找第一个小于k的数
            while (i < j && arr[j] >= k) {
                j--;
//                printf("-%d~~~%d\n", i, j);
            }
            // 互换
            if (i < j) {
                arr[i++] = arr[j];
//                printf("--%d~~~%d\n", i, j);
            }
            // 从左向右找第一个大于等于k的数
            while (i < j && arr[i] < k) {
                i++;
//                printf("---%d~~~%d\n", i, j);
            }
            if (i < j) {
                arr[j--] = arr[i];
//                printf("----%d~~~%d\n", i, j);
            }
//            display(arr, 10);
        }

        arr[i] = k;
//        printf("%d\n", k);
//        display(arr, 10);
        // 递归调用
        QuickSort(arr, low, i - 1);     // 排序k左边
        QuickSort(arr, i + 1, high);    // 排序k右边
    }
}

// 函数入口
int main() {
    int array[ARRAY_SIZE] = {12, 85, 25, 16, 34, 23, 49, 95, 17, 61};
    int length = ARRAY_SIZE;

    printf("排序前的数组：\n");
    display(array, length);

    printf("---------------------------------\n");
    QuickSort(array, 0, length - 1);  // 快速排序

    printf("排序后的数组：\n");
    display(array, length);

    return 0;
}

// 关键字：系统自己命名的
// 标示符：程序员自己在程序中起的名字