//
//  main.c
//  折半查找
//
//  Created by Shannon MYang on 2019/11/10.
//  Copyright © 2019 Shannon MYang. All rights reserved.
//

#include <stdio.h>
#include <time.h>

/*
 * 折半查找原理：
 * 1. 数组必须是有序的；
 * 2. 必须已知min和max（知道范围）；
 * 3. 动态计算mid的值，取出mid对应的值进行比较；
 * 4. 如果mid对应的值大于了需要查找的值，那么max要变小为mid-1
 * 5. 如果mid对应的值小于了需要查找的值，那么min要变大为mid+1
 */

int findKey (int nums[], int key, int length);
int findKey2 (int nums[], int key, int length);
int findKey3 (int nums[], int key, int length);

int main(int argc, const char * argv[]) {
    // 现在已知一个有序的数组，和一个key，要求从数组中找到key对应的索引的位置
    int nums[] = {1, 3, 5, 7, 9, 11};
    int key = 11;
    int length = sizeof(nums) / sizeof(nums[0]);
    
    clock_t startTime = clock();
//    int index = findKey(nums, key, length);
//    int index = findKey2(nums, key, length);
    int index = findKey3(nums, key, length);
    clock_t endTime = clock();
    printf("消耗的时间为 --- %lu毫秒?! \n", endTime - startTime);
    printf("index = %i \n", index);
    
    return 0;
}

// 对该方法进行封装，要求找到就返回对应的索引，找不到就返回-1
int findKey (int nums[], int key, int length)
{
    for (int i = 0; i < length; i++) {
        if (nums[i] == key) {
            // printf("%i \n", i);
            return i;
        }
    }
    return -1;
}

int findKey2 (int nums[], int key, int length)
{
    int min = 0;
    int max = length - 1;
    int mid = (min + max) / 2;
    
    while (key != nums[mid]) {
        
        // 判断如果要找的值，大于了取出的值，那么min要改变；
        if (key > nums[mid]) {
            min = mid + 1;
        }
        // 判断如果要找的值，小于了取出的值，那么max要改变；
        else if (key < nums[mid]) {
            max = mid - 1;
        }
        // 超出范围，数组中没有要查找的值
        if (min > max) {
            return -1;
        }
        // 每次改变完min和max都要重新计算mid
        mid = (min + max) / 2;
    }
    
    return mid;
}

int findKey3 (int nums[], int key, int length)
{
    int min, max, mid;
    min = 0;
    max = length - 1;
    
    // 只要还在我们的范围，就需要查找
    while (min <= max) {
        // 计算中间值
        mid = (min + max) / 2;
        // 判断如果要找的值，大于了取出的值，那么min要改变；
        if (key > nums[mid]) {
            min = mid + 1;
        }
        // 判断如果要找的值，小于了取出的值，那么max要改变；
        else if (key < nums[mid]) {
            max = mid - 1;
        }
        else {
            return mid;
        }
    }
    
    return -1;
}
