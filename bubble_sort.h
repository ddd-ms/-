#include<iostream>
void bubble_sort(int* pbegin, int* initpend, bool (*cmp)(int* a, int* b)) {
	int* pend = initpend;
	pend++;
	for (int* p = pend; p != pbegin; p--) {
		for (int* q =pbegin,*r = q++;r!=pend && q != p; q++,r++) {
			if (cmp(r, q) == false) {
				int t = *r;
				*r = *q;
				*q = t;
			}
		}
	}
}
