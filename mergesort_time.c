
#include <stdio.h>
#include <time.h>

void merge(int a[], int low, int mid, int hight) {
	int b[100000];
	int i = low;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= hight) {
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}

	while (i <= mid)
		b[k++] = a[i++];

	while (j <= hight)
		b[k++] = a[j++];

	k--;

	while (k >= 0) {
		a[low + k] = b[k];
		k--;
	}
}

void mergeSort(int a[], int low, int hight) {
	int mid;

	if (low < hight) {
		mid = (low + hight) / 2;
		mergeSort(a, low, mid);
		mergeSort(a, mid + 1, hight);
		merge(a, low, mid, hight);
	}
}

int main(void) {

	int arr[100000];
	int i;

	for (i = 0; i < sizeof(arr) / sizeof(int); i++) {
		arr[i] = i;
	}
	clock_t start = clock();
	mergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	clock_t end = clock();
	printf("\n합병정렬 best case 수행 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	//for(i = 0; i < sizeof(arr) / sizeof(int); i++)
		//printf("%d ", arr[i]);
}
