int* select( int* pbegin,int* pend, bool (*cmp)(int* a, int* b)) {
	int* select = pbegin;
	for (int* p =pbegin; p != pend; p++) {
		if (cmp(select, p) == false) {
			select = p;
		}
	}
	return select;
}

void select_sort(int* pbegin, int* initpend, bool (*cmp)(int* a, int* b)) {
	int* pend = initpend;
	pend++;
	for (int* p =pbegin; p != pend; p++) {
		int* ps = select(p, pend, cmp);
		int t = *p;
		*p = *ps;
		*ps = t;
	}
}