void shell_sort(int* arr, int len) {
	int temp, j;
	int step[] = { 1,3,7,11 };
	int maxstepi = 0;
	for (int i = 1; i < 4; i++) {// 4 == step.len();
		if (step[i] < len) maxstepi = i;
	}//获取最大可用步长
	//cout << step[maxstepi] << endl;
	for (; maxstepi >= 0; maxstepi--) {
		for (int i = maxstepi; i < len; i += step[maxstepi]) {
			temp = arr[i];
			for (j = i - step[maxstepi]; j >= 0 && arr[j] > temp; j -= step[maxstepi]) {
				arr[j + step[maxstepi] ] = arr[j];
			}
			arr[j + step[maxstepi] ] = temp;
		}
	}
}