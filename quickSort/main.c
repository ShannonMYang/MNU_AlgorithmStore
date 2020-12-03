
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

/*
 *��������display
 *���ã���ӡ����Ԫ��
 *������array - ��ӡ�����飬maxlen - ����Ԫ�ظ���
 *����ֵ����
 */
void display(int array[], int maxlen) {
    int i;

    for (i = 0; i < maxlen; i++) {
        printf("%-3d", array[i]);
    }
    printf("\n");
}

/*
 *��������QuickSort
 *���ã����������㷨
 *������
 *����ֵ����
 */
void QuickSort(int *arr, int low, int high) {
    if (low < high) {
        int i = low;
        int j = high;
        int k = arr[low];
        while (i < j) {
            // ���������ҵ�һ��С��k����
            while (i < j && arr[j] >= k) {
                j--;
//                printf("-%d~~~%d\n", i, j);
            }
            // ����
            if (i < j) {
                arr[i++] = arr[j];
//                printf("--%d~~~%d\n", i, j);
            }
            // ���������ҵ�һ�����ڵ���k����
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
        // �ݹ����
        QuickSort(arr, low, i - 1);     // ����k���
        QuickSort(arr, i + 1, high);    // ����k�ұ�
    }
}

// �������
int main() {
    int array[ARRAY_SIZE] = {12, 85, 25, 16, 34, 23, 49, 95, 17, 61};
    int length = ARRAY_SIZE;

    printf("����ǰ�����飺\n");
    display(array, length);

    printf("---------------------------------\n");
    QuickSort(array, 0, length - 1);  // ��������

    printf("���������飺\n");
    display(array, length);

    return 0;
}

// �ؼ��֣�ϵͳ�Լ�������
// ��ʾ��������Ա�Լ��ڳ������������