#include<stdlib.h>
void merge(int* a, int* t, int leftIndex, int rightIndex, int rightEnd) {
    int begin = leftIndex;
    int leftEnd = rightIndex - 1;
    int tIndex = leftIndex;
    while (leftIndex <= leftEnd && rightIndex <= rightEnd) {
        if (a[leftIndex] <= a[rightIndex]) t[tIndex++] = a[leftIndex++];
        else t[tIndex++] = a[rightIndex++];
    }
    while (leftIndex <= leftEnd) t[tIndex++] = a[leftIndex++];
    while (rightIndex <= rightEnd) t[tIndex++] = a[rightIndex++];
    for (int i = begin; i <= rightEnd; ++i) a[i] = t[i];
    return;
}
void msort(int* arr, int* tmp, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    msort(arr, tmp, left, mid);
    msort(arr, tmp, mid + 1, right);
    merge(arr, tmp, left, mid + 1, right);
}
void mergeSort(int* arr, int size) {
    int* tmp;
    tmp = (int*)malloc(sizeof(int) * size);
    if (!tmp)return;
    msort(arr, tmp, 0, size - 1);
    free(tmp);
}
