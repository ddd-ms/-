#include<iostream>
using namespace std;
void insertion_sort(int* arr, int len, bool (*cmp)(int* n1, int* n2)) {
	int temp;
	int i, j;
	for (i = 1; i < len; i++) {
		temp = arr[i];
		for (j = i-1; j >= 0 && cmp(&temp,&(arr[j])); j--) {
			arr[j+1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}
//void insertion_sort(int* pbegin, int* initpend, bool (*cmp)(int* n1, int* n2)) {
//	int cnt = 1;
//	for (int* p = pbegin; p != initpend; p++) {
//		cnt++;
//	}
//	insertion_sort(pbegin, cnt, cmp);
//}
void insertion_sort(int* pbegin, int* pend, bool (*cmp)(int* n1, int* n2)) {
	int temp;
	int* pEndBarrier = pend;
	int* pFrontBarrier = pbegin;
	pFrontBarrier--;
	pEndBarrier++;
	int* q, * r;
	for (int* p = pbegin; p != pEndBarrier; p++) {
		temp = *p;
		q = p;
		q--;
		for (; q != pFrontBarrier && cmp(&temp, q); q--) {
			r = q;
			r++;
			*r = *q;
		}
		*(++q) = temp;
	}
}
