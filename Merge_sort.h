void merge(int* arr, int* temp, int lb, int rb, int re, bool(*cmp)(int* p1, int* p2))
{
	int le = rb - 1;
	int copyindex = lb;
	int index = lb;
	while (lb <= le && rb <= re) {
		if (arr[lb] <= arr[rb]) temp[index++] = arr[lb++];
		else temp[index++] = arr[rb++];
;	}
	while (lb <= le) temp[index++] = arr[lb++];
	while (rb <= re)temp[index++] = arr[rb++];
	for (int i = copyindex; i <= re; i++) {
		arr[i] = temp[i];
	}
}
void msort(int* arr, int* temp, int left, int right, bool(*cmp)(int* p1, int* p2)) {
	if (left >= right) return;
	int mid = (left + right) / 2;
	msort(arr, temp, left, mid,cmp);
	msort(arr, temp, mid + 1, right,cmp);
	merge(arr, temp, left, mid+1, right,cmp);	
}

void merge_sort(int* arr, int len,bool(*cmp)(int* p1,int* p2)) {
	int* temp = new int[len];
	if (!temp)return;
	msort(arr, temp, 0, len-1,cmp);
	delete[]temp;
}

