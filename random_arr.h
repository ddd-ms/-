#include<ctime>
#include<cstdlib>
#include<iostream>
using namespace std;
int* get_RandArr(int len) {
	int* arr = new int[len];
	srand((unsigned)time(0));
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % 100;
	}
	return arr;
}